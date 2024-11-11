from collections import deque
N,Q=map(int, input().split())

#重複分を引く

class BIT:
    def __init__(self, n):
        self.n = n
        self.data = [0]*(n+1)
        self.el = [0]*(n+1)
        
    def sum(self, i):
        s = 0
        while i > 0:
            s += self.data[i]
            i -= i & -i
        return s

    # I: idx(base: 1), x: value
    def add(self, i, x):
        # assert i > 0
        self.el[i] += x
        while i <= self.n:
            self.data[i] += x
            i += i & -i
            
    # i<x<=j 
    def get(self, i, j=None):
        if j is None:
            return self.el[i]
        return self.sum(j) - self.sum(i)

query=[]

C=list(map(int, input().split()))
for i in range(Q):
    l, r=map(int, input().split())
    query.append((l,r,i))
query=sorted(query, key=lambda x: -x[1])

state=[-1]*N
seg=BIT(N+1)
ans=[0]*Q

for i in range(N):
    while query and query[-1][1]<i+1:
        l,r,j=query.pop()
        ans[j]=r-l+1-(seg.get(l-1,r))

    c=C[i]
    if state[c-1]==-1:
        state[c-1]=i+1
    else:
        idx=state[c-1]
        seg.add(idx,1)
        state[c-1]=i+1
    while query and query[-1][1]==i+1:
        lq,rq,j=query.pop()
        ans[j]=rq-lq+1-(seg.get(lq-1,rq))
        #print(lq, rq, seg.get(lq-1,rq))



for a in ans:
    print(a)
