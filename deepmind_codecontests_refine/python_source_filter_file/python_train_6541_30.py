import functools
N, C = map(int, input().split())
T = [[0 for i in range(10 ** 5 + 1)] for j in range(C)]
for i in range(N):
  s, t, c = map(int, input().split())
  for j in range(s - 1, t + 1):
    T[c - 1][j] = 1
ans = 0
for i in range(10 ** 5 + 1):
  r = 0
  for j in range(C):
    r += T[j][i]
  ans = max(ans, r)
print(ans)