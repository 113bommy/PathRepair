n = int(input())
p = [1.0] + list(map(float,input().split()))
dp = [[0]*(n+1) for _ in range(n+1)]
dp[0][0] = 1.0
for i in range(1,n+1):
  dp[i][0] = dp[i-1][0]*(1.0-p[i])
  for j in range(1,i+1):
    dp[i][j] = dp[i-1][j-1]*p[i] + dp[i-1][j]*(1-p[i])
print(sum(dp[n][j] for j in range(n//2+1,n+1)))
