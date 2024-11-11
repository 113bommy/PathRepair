K = input()
d = int(input())
mod = 10**9+7
n = len(K)
dp = [[[0 for k in range(2)] for i in range(d)] for j in range(n+1)]
dp[0][0][0] = 1
for i in range(1,n+1):
  s = int(K[i-1])
  for j in range(d):
    for k in range(10):
      r = (j+k)%d
      dp[i][r][1] += dp[i-1][j][1]
      if k < s:
        dp[i][r][1] += dp[i-1][j][0]
      dp[i][r][1] %= mod
    dp[i][(j+s)%d][0] = dp[i-1][j][0]
print(sum(dp[n][0])-1)