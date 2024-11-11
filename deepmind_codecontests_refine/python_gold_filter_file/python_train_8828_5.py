import sys
sys.setrecursionlimit(10 ** 5 + 1)
N,M = map(int,input().split())

G = [[] for i in range(N)]
for i in range(M):
  x,y = map(int,input().split())
  G[x - 1].append(y - 1)

dp = [-1] * N # dp[i] = 頂点iから進むことが出来る深さ
def search(v):
  if dp[v] != -1:
    return dp[v]
  max_depth = 0
  for child in G[v]:
    max_depth = max(max_depth, search(child) + 1)
    
  dp[v] = max(dp[v], max_depth)
  return dp[v]

for i in range(N):
  search(i)

print(max(dp))
