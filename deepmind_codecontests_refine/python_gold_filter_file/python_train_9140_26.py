n = int(input())
P = list(map(float, input().split()))
dp = [[0]*(n+1) for _ in range(n+1)]
dp[0][0] = 1
for i in range(n):
  for j in range(n+1):
    if j==0:
      dp[i+1][j] = dp[i][j]*(1-P[i])
    else:
      dp[i+1][j] = dp[i][j-1]*P[i] + dp[i][j]*(1-P[i])
print(sum(dp[n][1+n//2:]))