from collections import defaultdict, deque

n, m = [int(i) for i in input().split()]

g = defaultdict(set)

edges = []

for i in range(m):
  f, s = [int(j) for j in input().split()]
  edges.append((f, s))
  g[f].add(s)
  g[s].add(f) 

triangles = set()

for e in edges:
  f, s = e
  i = g[f] & g[s]
  if len(i) > 0:
    for common in i:
      triangles.add(tuple(sorted([f, s, common])))

if len(triangles) == 0:
  print(-1)
else:
  min_rec = None

  for t in triangles:
    rec = len(g[t[0]]) + len(g[t[1]]) + len(g[t[2]])
    if min_rec is None or rec < min_rec:
      min_rec = rec

  print(rec - 6)

