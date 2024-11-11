from collections import defaultdict as dd
import sys
sys.setrecursionlimit(6000)
N, M, P = map(int, input().split())
edges = []
revedgedict = dd(dict)
for _ in range(M):
  f, t, c = map(int, input().split())
  edges.append((f-1, t-1, -(c-P)))
  revedgedict[t-1][f-1] = 1

# Nに到達できない頂点を削除
visited = [False] * N
def dfs(f):
  visited[f] = True
  for t in revedgedict[f].keys():
    if not visited[t]:
      dfs(t)
dfs(N-1)

# ベルマンフォード
INF = float('inf')
d = [float('inf')] * N
d[0] = 0
for i in range(M):
  updated = False
  for f, t, c in edges:
    if d[f] != INF and visited[t] and d[t] > d[f] + c:
      d[t] = d[f] + c
      updated = True
  if not updated:
    break
else:
  print(-1)
  exit()
print(max(-d[-1], 0))