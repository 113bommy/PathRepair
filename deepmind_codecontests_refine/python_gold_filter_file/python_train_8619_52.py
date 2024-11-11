from heapq import heapify,heappop,heappush
import sys
read=sys.stdin.readline
class mset:
    def __init__(self):
        self.p,self.q=[],[]
        heapify(self.p);heapify(self.q)
    def add(self,a):
        heappush(self.p,a)
    def delete(self,a):
            heappush(self.q,a)
    def minimum(self):
        while self.q and self.p[0]==self.q[0]:
            heappop(self.p);heappop(self.q)
        return self.p[0] if self.p else None

N,Q=map(int,read().split())
event=[]
for i in range(N):
    S,T,X=map(int,read().split())
    event.append((1,S-X,X))
    event.append((0,T-X,X))

s=mset()
now=0
for i in range(Q):
    D=int(read())
    event.append((2,D,0))
event.sort(key=lambda x:(x[1],x[0]))

for c,t,w in event:
    if c==0:
        s.delete(w)
    elif c==1:
        s.add(w)
    else:
        m=s.minimum()
        print(-1 if m==None else m)