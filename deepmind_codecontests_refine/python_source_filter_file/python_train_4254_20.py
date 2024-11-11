N, M = map(int, input().split())
D = {i: 0 for i in range(1, N + 1)}
for i in range(M):
  a, b = map(int, input().split())
  D[a] += 1
  D[b] += 1
p = 0
for i in D:
  if i % 2 == 1:
    p = 1
if p == 0:
  print("YES")
else:
  print("NO")
