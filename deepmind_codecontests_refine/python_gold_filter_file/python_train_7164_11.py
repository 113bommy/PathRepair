N, M, Q = map(int, input().split())
dp = [[0]*N for i in range(N)]
for i in range(M):
  l, r = map(int, input().split())
  dp[r-1][l-1] += 1
for i in range(N):
  for j in range(N-1, 0, -1):
    dp[i][j-1] += dp[i][j]
for j in range(N):
  for i in range(N-1):
    dp[i+1][j] += dp[i][j]
for i in range(Q):
  p, q = map(int, input().split())
  print(dp[q-1][p-1])