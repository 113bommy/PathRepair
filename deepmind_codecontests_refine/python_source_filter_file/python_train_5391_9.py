import sys
input=lambda: sys.stdin.readline().rstrip()
n=int(input())
mod=10**9+7


n_max=(10**5+1)
F,FI=[0]*(n_max+1),[0]*(n_max+1)
F[0],FI[0]=1,1
for i in range(n_max):
  F[i+1]=(F[i]*(i+1))%mod
FI[n_max-1]=pow(F[n_max-1],mod-2,mod)
for i in reversed(range(n_max-1)):
  FI[i]=(FI[i+1]*(i+1))%mod
def comb(x,y):
  return (F[x]*FI[x-y]*FI[y])%mod
def I(x):
  return pow(x,mod-2,mod)

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

Used=[False]*n
C=[0]*n
for i in reversed(range(n)):
  v=TS[i]
  Used[v]=True
  for g in edge[v]:
    if not Used[g]:
      C[g]+=C[v]+1

D=[1]*n
for i in reversed(range(n)):
  v=TS[i]
  D[v]=(D[v]*F[C[v]])%mod
  if Par[v]!=-1:
    D[Par[v]]=(D[Par[v]]*I(F[C[v]+1])*D[v])%mod
E=[1]*n
for i in range(n):
  v=TS[i]
  if Par[v]!=-1:
    cur=E[v]*FI[n-C[v]-1]
  else:
    cur=1
  for e in edge[v]:
    if e!=Par[v]:
      cur=(cur*FI[C[e]+1]*D[e])%mod
  for e in edge[v]:
    if e!=Par[v]:
      E[e]=(cur*F[n-2-C[e]]*F[C[e]+1]*I(D[e]))%mod
for i in range(n):
  print((comb(n-1,C[i])*D[i]*E[i])%mod)