from collections import deque

class LazySegtree():
    def __init__(self,n,init_val,merge_func,ide_ele):
        self.n=n
        self.ide_ele=ide_ele
        self.merge_func=merge_func
        self.val=[0 for i in range(1<<n)]
        self.merge=[0 for i in range(1<<n)]
        self.parent=[-1 for i in range(1<<n)]
        self.lazy=[0 for i in range(1<<n)]
        deq=deque([1<<(n-1)])
        res=[]
        while deq:
            v=deq.popleft()
            res.append(v)
            if not v&1:
                gap=(v&-v)//2
                self.parent[v-gap]=v
                deq.append(v-gap)
                self.parent[v+gap]=v
                deq.append(v+gap)
        for v in res[::-1]:
            if v-1<len(init_val):
                self.val[v-1]=init_val[v-1]
            else:
                self.val[v-1]=10**18
            self.merge[v-1]=self.val[v-1]
            if not v&1:
                gap=(v&-v)//2
                self.merge[v-1]=self.merge_func(self.merge[v-1],self.merge[v-gap-1],self.merge[v+gap-1])

    def lower_kth_update(self,nd,k,x):
        if k==-1:
            return
        maxi=nd-(nd&-nd)+1+k
        ids=self.idgetter(nd,maxi)
        for pos in ids:
            gap=(pos&-pos)//2
            self.propagate(pos)
            if pos<=maxi:
                self.val[pos-1]+=x
                self.lazy[pos-gap-1]+=x*(gap!=0)

        if pos&1:
            self.merge[pos-1]=self.val[pos-1]
            ids.pop()
        ids=ids[::-1]
        for pos in ids:
            gap=(pos&-pos)//2
            self.merge[pos-1]=self.merge_func(self.val[pos-1],self.merge[pos-gap-1]+self.lazy[pos-gap-1],self.merge[pos+gap-1]+self.lazy[pos+gap-1])

    def upper_kth_update(self,nd,k,x):
        if k==-1:
            return
        mini=nd+(nd&-nd)-1-k
        ids=self.idgetter(nd,mini)
        for pos in ids:
            gap=(pos&-pos)//2
            self.propagate(pos)
            if pos>=mini:
                self.val[pos-1]+=x
                self.lazy[pos+gap-1]+=x*(gap!=0)

        if pos&1:
            self.merge[pos-1]=self.val[pos-1]
            ids.pop()
        ids=ids[::-1]
        for pos in ids:
            gap=(pos&-pos)//2
            self.merge[pos-1]=self.merge_func(self.val[pos-1],self.merge[pos-gap-1]+self.lazy[pos-gap-1],self.merge[pos+gap-1]+self.lazy[pos+gap-1])

    def update(self,l,r,x):
        pos=1<<(self.n-1)
        end=self.range_goal(l+1,r+1)
        ids=self.idgetter(pos,end)
        for pos in ids:
            self.propagate(pos)
        gap=(pos&-pos)//2
        self.val[pos-1]+=x
        self.upper_kth_update(pos-gap,pos-1-l-1,x)
        self.lower_kth_update(pos+gap,r-pos,x)

        if pos&1:
            self.merge[pos-1]=self.val[pos-1]
            ids.pop()
        for pos in ids[::-1]:
            gap=(pos&-pos)//2
            self.merge[pos-1]=self.merge_func(self.val[pos-1],self.merge[pos-gap-1]+self.lazy[pos-gap-1],self.merge[pos+gap-1]+self.lazy[pos+gap-1])

    def lower_kth_merge(self,nd,k,debug=False):
        res=self.ide_ele
        if k==-1:
            return res
        maxi=nd-(nd&-nd)+1+k
        ids=self.idgetter(nd,maxi)
        for pos in ids:
            self.propagate(pos)

        stack=[self.ide_ele]
        if pos&1:
            self.merge[pos-1]=self.val[pos-1]
            stack.append(self.merge[pos-1])
            ids.pop()
        for pos in ids[::-1]:
            gap=(pos&-pos)//2
            if pos<=maxi:
                self.merge[pos-1]=self.merge_func(self.val[pos-1],self.merge[pos-gap-1]+self.lazy[pos-gap-1])
                stack.append(self.merge[pos-1])
                self.merge[pos-1]=self.merge_func(self.merge[pos-1],self.merge[pos+gap-1]+self.lazy[pos+gap-1])
            else:
                self.merge[pos-1]=self.merge_func(self.val[pos-1],self.merge[pos-gap-1]+self.lazy[pos-gap-1],self.merge[pos+gap-1]+self.lazy[pos+gap-1])
        return self.merge_func(stack)

    def upper_kth_merge(self,nd,k):
        res=self.ide_ele
        if k==-1:
            return res
        mini=nd+(nd&-nd)-1-k
        ids=self.idgetter(nd,mini)
        for pos in ids:
            self.propagate(pos)

        stack=[self.ide_ele]
        if pos&1:
            self.merge[pos-1]=self.val[pos-1]
            stack.append(self.merge[pos-1])
            ids.pop()
        for pos in ids[::-1]:
            gap=(pos&-pos)//2
            if pos>=mini:
                self.merge[pos-1]=self.merge_func(self.val[pos-1],self.merge[pos+gap-1]+self.lazy[pos+gap-1])
                stack.append(self.merge[pos-1])
                self.merge[pos-1]=self.merge_func(self.merge[pos-1],self.merge[pos-gap-1]+self.lazy[pos-gap-1])
            else:
                self.merge[pos-1]=self.merge_func(self.val[pos-1],self.merge[pos-gap-1]+self.lazy[pos-gap-1],self.merge[pos+gap-1]+self.lazy[pos+gap-1])
        return self.merge_func(stack)

    def query(self,l,r):
        pos=1<<(self.n-1)
        end=self.range_goal(l+1,r+1)
        ids=self.idgetter(pos,end)
        for pos in ids:
            self.propagate(pos)
        gap=(pos&-pos)//2
        left=self.upper_kth_merge(pos-gap,pos-1-l-1)
        right=self.lower_kth_merge(pos+gap,r-pos)
        res=self.merge_func(left,right,self.val[pos-1])
        return res

    def propagate(self,pos):
        if self.lazy[pos-1]:
            self.val[pos-1]+=self.lazy[pos-1]
            self.merge[pos-1]+=self.lazy[pos-1]
            if not pos&1:
                gap=(pos&-pos)//2
                self.lazy[pos-gap-1]+=self.lazy[pos-1]
                self.lazy[pos+gap-1]+=self.lazy[pos-1]
            self.lazy[pos-1]=0
        return

    def idgetter(self,start,goal):
        res=[]
        pos=goal
        while pos!=start:
            res.append(pos)
            pos=self.parent[pos]
        res.append(start)
        return res[::-1]

    def range_goal(self,l,r):
        res=0
        if l==r:
            return l
        while l.bit_length()==r.bit_length():
            n=l.bit_length()-1
            res+=1<<n
            l-=1<<n
            r-=1<<n
            if l==0:
                return res
        return res+(1<<(r.bit_length()-1))

import sys

input=sys.stdin.buffer.readline

ide_ele=10**18

N,M=map(int,input().split())

init=[0 for i in range(M+2)]
for i in range(1,M+1):
    init[0]+=1
    init[i+1]-=1
for i in range(1,M+1):
    init[i]+=init[i-1]
init[-1]=0

LST=LazySegtree((M+2).bit_length(),init,merge_func=min,ide_ele=10**18)

hito=[tuple(map(int,input().split())) for i in range(N)]
hito.sort()

add=M-N
for l,r in hito:
    LST.update(0,r,-1)
    m=LST.query(l+1,M+1)+l
    add=min(m,add)

print(max(-add,0))
