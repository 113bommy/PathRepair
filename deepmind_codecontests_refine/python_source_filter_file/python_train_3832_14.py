n = int(input())
adj = [[] for _ in range(n)]
for _ in range(n-1):
  u, v, w = map(int, input())
  adj[u-1].append((w, v-1))
  adj[v-1].append((w, u-1))
paint = [None] * n
paint[0] = 0
stack = [0]
while stack:
  u = stack.pop()
  for w, v in adj[u]:
    if paint[v] is None:
      stack.append(v)
      paint[v] = (paint[u] + w) % 2
for p in paint:
  print(p)