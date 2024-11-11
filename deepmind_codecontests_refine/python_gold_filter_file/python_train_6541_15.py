import sys
input = sys.stdin.readline
N, C = map(int, input().split())
c = [list(map(int, input().split())) for _ in range(N)]
t = [[0] * (10 ** 5 + 1) for _ in range(C + 1)]
for i in range(N):
  for j in range(c[i][0], c[i][1] + 1):
    t[c[i][2]][j] = 1
res = 0
for i in range(10 ** 5 + 1):
  p = 0
  for j in range(C + 1):
    p += t[j][i]
  res = max(p, res)
print(res)