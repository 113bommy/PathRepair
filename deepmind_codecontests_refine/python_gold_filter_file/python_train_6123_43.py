import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**6)
mod=10**9+7
N=int(input())
G=[[] for _ in range(N+1)]
for _ in range(N-1):
    x,y=map(int, input().split())
    G[x].append(y)
    G[y].append(x)
b=[1]*(N+1)
w=[1]*(N+1)
def dfs(pre,n):
  for i in G[n]:
    if i==pre:
      continue
    dfs(n,i)
    b[n]*=w[i]
    b[n]%=mod
    w[n]*=b[i]+w[i]
    w[n]%=mod

dfs(0,1)
print((b[1]+w[1])%mod)