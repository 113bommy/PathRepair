from collections import deque

R=lambda: map(int, input().split())

n, m = R()
g = [[] for _ in range(n)]
for _ in range(m):
  u, v = R()
  g[u - 1].append(v - 1)
  g[v - 1].append(u - 1)

r = 'Yes' + [None] * (n - 1)
V = [True] + [False] * (n - 1)
q = deque([0])
while q:
  u = q.popleft()
  for v in g[u]:
    if not V[v]:
      V[v] = True
      r[v] = u + 1
      q.append(v)

print(*(['No'], r)[all(r)], sep='\n')
