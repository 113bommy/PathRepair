import sys
input = sys.stdin.readline
N, M = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(N)]
t = [0] * (M + 1)
p = [0] * N
s = set()
res = float("inf")
for _ in range(M):
  t = [0] * (M + 1)
  for i in range(N): t[a[i][p[i]]] += 1
  x = 0
  y = 0
  for j in range(1, M + 1):
    if y < t[j]:
      x = j
      y = t[j]
  s.add(x)
  for i in range(N):
    while a[i][p[i]] in s:
      p[i] += 1
      if p[i] >= M:
        break
  if max(p) >= M: break
  res = min(res, max(t))
  #print(t, p)
print(min(res, N))