from collections import deque
n=int(input())
mod=10**9+7
G=[[] for i in range(n)]
for i in range(n-1):
  x,y=map(int,input().split())
  x=x-1
  y=y-1
  G[x].append(y)
  G[y].append(x)
A=[0]*n
A[0]=1
B=deque([0])
C=[0]
GG=[[] for i in range(n)]
while len(B)>0:
  v=B[0]
  B.popleft()
  for i in range(len(G[v])):
    if A[G[v][i]]==0:
      A[G[v][i]]=1
      B.append(G[v][i])
      C.append(G[v][i])
      GG[v].append(G[v][i])
C=C[::-1]
dp=[[0]*2 for i in range(n)]
for i in range(n):
  if len(GG[C[i]])==0:
    dp[C[i]]=[1,1]
  else:
    a=1
    b=1
    for j in range(len(GG[C[i]])):
      a=(a*(dp[GG[C[i]][j]][0]+dp[GG[C[i]][j]][1]))%mod
      b=(b*dp[GG[C[i]][j]][0])%mod
    dp[C[i]][0]=a
    dp[C[i]][1]=b
print(dp[0][0]+dp[0][1])