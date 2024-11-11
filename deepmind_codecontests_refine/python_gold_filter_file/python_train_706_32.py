N, K = map(int, input().split())
A = list(map(int, input().split()))
MOD = 10**9 + 7

dp = [[0]*(K+1) for i in range(N)]
for i, a in enumerate(A):
  if i == 0:
    for j in range(a+1):
      dp[0][j] = 1
  
  else:
    dp[i][0] = 1
    for j in range(1, K+1):
      dp[i][j] = dp[i][j-1] + dp[i-1][j]
      if j > a:
        dp[i][j] -= dp[i-1][j-a-1]

      dp[i][j] %= MOD

print(dp[N-1][K])