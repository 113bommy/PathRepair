from collections import deque
n=int(input())
A=[]
for i in range(n):
  A.append([int(i) for i in input().split()])
nn=n*(n-1)//2
F=[[0]*(n+1) for _ in range(n+1)]
cur=0
for i in range(1,n):
  for j in range(i+1,n+1):
    F[i][j]=cur
    F[j][i]=cur
    cur+=1
Edge=[[] for _ in range(nn)]
Deg=[0]*nn
for i in range(n):
  s=F[i+1][A[i][0]]
  for j in range(1,n-1):
    t=F[i+1][A[i][j]]
    Edge[s].append(t)
    Deg[t]+=1
    s=t
ans=0
S=[i for i in range(nn) if Deg[i]==0]
D=deque()
DD=deque(S)
while DD:
  D=DD
  DD=deque()
  while D:
    d=D.popleft()
    for g in Edge[d]:
      Deg[g]-=1
      if Deg[g]==0:
        DD.append(g)
        S.append(g)
  ans+=1
print(-1 if ans==0 else ans)