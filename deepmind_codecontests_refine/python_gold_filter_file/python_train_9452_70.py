N, M, P = map(int, input().split())
E = [[] for _ in range(M)]
for i in range(M):
  a, b, c = map(int, input().split())
  E[i] = [a - 1, b - 1, c]
D = [None] * N
D[0] = 0
for _ in range(N):
  for a, b, c in E:
    if D[a] == None:
      continue
    if D[b] == None:
      D[b] = D[a] + c - P
    else:
      D[b] = max(D[b], D[a] + c - P)
_D = D[-1]
for _ in range(N):
  for a, b, c in E:
    if D[a] == None:
      continue
    if D[b] == None:
      D[b] = D[a] + c - P
    else:
      D[b] = max(D[b], D[a] + c - P)
if D[-1] > _D:
  print(-1)
else:
  print(max(D[-1], 0))