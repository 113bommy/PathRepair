N = int(input())
S = [list(map(int, list(input()))) for i in range(N)]

# 奇数長のループがあるかどうかをチェック
node_to_idx = {}
visited = [False] * N
def dfs(node, par, n):
  global node_to_idx
  res = True
  for i, s in enumerate(S[node]):
    if s and i != par:
      if i in node_to_idx:
        idx = node_to_idx[i]
        if (n - idx) % 2:
          return False
        else:
          return True
      else:
        if visited[i]:
          continue
        visited[i] = True
        node_to_idx[i] = n
        res *= dfs(i, node, n+1)
  return res

node_to_idx[0] = 0
visited[0] = True
res = dfs(0, -1, 1)
if res:
  from scipy.sparse.csgraph import floyd_warshall
  import numpy as np
  dist = floyd_warshall(S).astype(int)
  print(dist.max() + 1)
else:
  print(-1)