n, m = list(map(int, input().split()))
MOD = 10**9+7
dp = [[0 for i in range(2010)] for i in range(2010)]
for i in range(2010):
  dp[i][0] = 1
  dp[0][i] = 1
s = list(map(int, input().split()))
t = list(map(int, input().split()))
for i in range(1, n+1):
  for j in range(1, m+1):
    dp[i][j] = (dp[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1])%MOD
    if s[i-1]==t[j-1]:
      dp[i][j] = (dp[i][j]+dp[i-1][j-1])%MOD
print(dp[n][m])