import sys
input=lambda: sys.stdin.readline().rstrip()
mod=10**9+7
n=int(input())
edge=[[] for i in range(n)]
for i in range(n-1):
  a,b=map(int,input().split())
  edge[a-1].append(b-1)
  edge[b-1].append(a-1)
Ans=[]
inf=10**6

#親と入次数を求める
Par=[inf]*n
Par[0]=-1
Deg=[0]*n
Deg[0]=0
Chk=[0]
while Chk:
  c=Chk.pop()
  for next in edge[c]:
    if Par[next]==inf:
      Par[next]=c
      Deg[next]+=1
      Chk.append(next)
 
#トポソする
from collections import deque
TS=list(v for v in range(n) if Deg[v]==0)
D=deque(TS)
while D:
  v=D.popleft()
  for t in edge[v]:
    if t!=Par[v]:
      Deg[t]-=1
      if Deg[t]==0:
        D.append(t)
        TS.append(t)

C1,C2=[0]*n,[0]*n
for i in reversed(range(n)):
  v=TS[i]
  if len(edge[v])==1 and Par[v]!=-1:
    C1[v]=1
    C2[v]=1
  else:
    c1,c2=1,1
    for g in edge[v]:
      if g==Par[v]:
        continue
      else:
        c1*=C1[g]+C2[g]
        c2*=C1[g]
    C1[v]=c1%mod
    C2[v]=c2%mod
print(C1[0]+C2[0])

