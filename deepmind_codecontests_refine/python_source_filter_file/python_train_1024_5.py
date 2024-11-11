N, M = map(int, input().split())
D = [[float("inf")]*N for i in range(N)]
for i in range(N):
  D[i][i] = 0
abcs = []
for i in range(M):
  a, b, c = map(int, input().split())
  a, b = a-1, b-1
  abcs.append((a, b, c))
  D[a][b] = c
  D[b][a] = c
for a in range(N):
  for b in range(N):
    for k in range(N):
      D[a][b] = min(D[a][b], D[a][k]+D[k][b])
#print(D)
r = 0
for m in range(M):
  a, b, c = abcs[m]
  if c > D[a][b]:
    r += 1
print(r)
