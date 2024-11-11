n,q = map(int,input().split())
c = tuple(map(int,input().split()))
qs = [[] for _ in range(n)]
for i in range(q):
  l,r = map(int,input().split())
  l -= 1
  r -= 1
  qs[l].append((r,i))

class BIT:
    def __init__(self,n):
        self.num=n
        self.dat=[0]*(self.num+1)
        self.depth=n.bit_length()
    
    def add(self,i,x):
        i+=1
        while i<=self.num:
            self.dat[i]+=x
            i+=i&-i
    
    def sum(self,i):
        i+=1
        s=0
        while i>0:
            s+=self.dat[i]
            i-=i&-i
        return s
    
    def lower_bound(self,x):
        sum_=0
        pos=0
        for i in range(self.depth,-1,-1):
            k=pos+(1<<i)
            if k<=self.num and sum_+self.dat[k]<x:
                sum_+=self.dat[k]
                pos+=1<<i
        return pos, sum_

ps = [-1 for _ in range(n)]
pi = [-1 for _ in range(n)]
for i in range(n):
  l = pi[c[i]]
  if l != -1:
    ps[l] = i
  pi[c[i]] = i
    
d = BIT(n)
ans = [0 for _ in range(q)]
for x in range(n-1,-1,-1):
  if ps[x] != -1:
    d.add(ps[x],1)
  for r,i in qs[x]:
    ans[i] = (r-x+1)-d.sum(r)

for i in range(q):
  print(ans[i])
