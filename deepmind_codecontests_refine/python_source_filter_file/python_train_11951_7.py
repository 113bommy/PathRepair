N, K = map(int, input().split())
H = list(map(int, input().split())) + [0]
dp = [[10**12]*(K+2) for _ in range(N+1)]
dp[0][0] = 0
for i in range(N):
  for j in range(min(i+1, K) + 1):
    for k in range(j + 1):
      dp[i+1][j] = min(dp[i+1][j], dp[i-k][j-k] + max(H[i] - H[i-k-1], 0))
ans = min(dp[-1])
for i in range(K):
  ans = min(ans, dp[N-i][K-i])
print(ans)