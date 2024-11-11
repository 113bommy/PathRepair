from sys import exit, setrecursionlimit, stderr
from functools import reduce
from itertools import *
from collections import *
from bisect import bisect
from heapq import *

def read():
  return int(input())
 
def reads():
  return [int(x) for x in input().split()]

N, M = reads()
edges = [[] for _ in range(N)]
edgesc = defaultdict(lambda: [])
for _ in range(M):
  p, q, c = reads()
  p, q = p-1, q-1
  edges[p].append((q, c))
  edges[q].append((p, c))
  edgesc[p, c].append(q)
  edgesc[q, c].append(p)

INF = 1 << 30
def dijkstra(edges, s):
  result = defaultdict(lambda: INF)
  result[s, -1] = 0
  que = deque([(0, s, -1)])
  while len(que) > 0:
    (d, u, c) = que.popleft()
    if result[u, c] < d:
      continue
    if c < 0:
      for (t, c2) in edges[u]:
        if d + 1 < result[t, c2]:
          result[t, c2] = d + 1
          que.append((d + 1, t, c2))
    else:
      for t in edgesc[u, c]:
        if d < result[t, c]:
          result[t, c] = d
          que.appendleft((d, t, c))
      if d < result[u, -1]:
        result[u, -1] = d
        que.appendleft((d, u, -1))
  return result

dist = dijkstra(edges, 0)
try:
  print(min(d for (u, _), d in dist.items() if u == N-1))
except ValueError:
  print(-1)