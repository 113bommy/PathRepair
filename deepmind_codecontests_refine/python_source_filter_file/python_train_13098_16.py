import sys
from collections import defaultdict as dd
input = sys.stdin.readline
N, M, s, t = map(int, input().split())
e = dd(list)
ee = dd(list)
for i in range(M):
  u, v, a, b = map(int, input().split())
  e[u].append((v, a))
  e[v].append((u, a))
  ee[u].append((v, b))
  ee[v].append((u, b))

import heapq
class dijkstra:
  def __init__(self, n, e):
    self.e = e
    self.n = n
  def path(self, s, t):
    d = [float("inf")] * (self.n + 1)
    vis = set()
    d[s] = 0
    h = [s]
    while not t in vis and len(h):
      v = heapq.heappop(h)
      v1 = v % (10 ** 10)
      v0 = v // (10 ** 10)
      if v1 in vis: continue
      vis.add(v1)
      for p in self.e[v1]:
        d[p[0]] = min(d[p[0]], d[v1] + p[1])
        if p[0] in vis: continue
        heapq.heappush(h, d[p[0]] * (10 ** 10) + p[0])
    return d
dij = dijkstra(N, e)
edij = dijkstra(N, e)
p = dij.path(s, 0)
revp = edij.path(t, 0)
mny = pow(10, 15)
table = [0] * (N + 1)
for x in range(1, N + 1):
  table[x] = mny - p[x] - revp[x]
csmx = [0] * (N + 1)
for i in range(N, 0, -1): csmx[i - 1] = max(csmx[i - 1], table[i], csmx[i])
for i in range(N): print(csmx[i])