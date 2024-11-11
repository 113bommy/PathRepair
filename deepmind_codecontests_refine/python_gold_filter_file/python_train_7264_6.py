from heapq import *
N=int(input())
X=[list(map(int,input().split())) for i in range(N)]
X.sort(reverse=True)
Q=[]
heapify(Q)
Y=0
mod=998244353
for i in range(N):
  Y=1
  while len(Q):
    if Q[0][0]<X[i][0]+X[i][1]:
      Y=Y*Q[0][1]%mod
      heappop(Q)
    else:
      break
  heappush(Q,(X[i][0],Y+1))
P=1
while len(Q):
  P=P*heappop(Q)[1]%mod
print(P)