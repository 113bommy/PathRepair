"""This code was written by
Russell Emerine - linguist,
mathematician, coder,
musician, and metalhead."""
n = int(input())
a = []
for x in input().split():
  x = int(x)
  if x: a.append(x)
n = len(a)
edges = set()
for d in range(60):
  p = 1 << d
  c = []
  for i in range(n):
    x = a[i]
    if x & p:
      c.append(i)
      if len(c) > 2:
        import sys
        print(3)
        sys.exit()
  if len(c) == 2:
    edges.add((c[0], c[1]))
m = n + 1
adj = [[][:] for _ in range(n)]
for u, v in edges:
  adj[u].append(v)
  adj[v].append(u)
from collections import deque
for r in range(n):
  v = [False] * n
  p = [-1] * n
  d = [n + 1] * n
  d[0] = 0
  s = deque([r])
  while len(s):
    h = s.popleft()
    v[h] = True
    for c in adj[h]:
      if p[h] == c:
        continue
      elif v[c]:
        m = min(d[h] + 1 + d[c], m)
      else:
        d[c] = d[h] + 1
        v[c] = True
        p[c] = h
        s.append(c);
if m == n + 1: m = -1
print(m)

