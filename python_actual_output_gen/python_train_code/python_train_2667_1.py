n = int(input())

a = 0
p = {x: 0 for x in range(1, n+1)}
for _ in range(n-1):
  u, v = map(int, input().split())
  p[u] += 1
  p[v] += 1
  if p[u] > 1:
    a += 1
  if p[v] > 1:
    a += 1
print(a)