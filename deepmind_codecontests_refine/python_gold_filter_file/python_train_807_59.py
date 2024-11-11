N = int(input())
A = list(map(int, input().split()))

D = [[0] * 2 for _ in range(N)]

for i in range(N):
  D[i] = [i, A[i]]

D.sort(key = lambda x: x[1], reverse = True)

DP = [[0] * (N + 1) for _ in range(N + 1)]
for i in range(N):
  n, x = D[i]
  t = i + 1
  for j in range(t + 1):
    l = j
    r = t - j
    rr = N - 1 - r
    if l != 0:
      DP[l][r] = DP[l - 1][r] + abs(n - l + 1) * x
    if r != 0:
      DP[l][r] = max(DP[l][r], DP[l][r - 1] + abs(rr + 1 - n) * x)

ans = 0
for i in range(N + 1):
  ans = max(ans, DP[i][N - i])
print(ans)
