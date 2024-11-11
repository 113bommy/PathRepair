s = input()
MOD = 10**9+7

dp = [[0 for i in range(13)] for i in range(len(s)+1)]
dp[0][0] = 1

for i in range(len(s)):
  if s[i]=='?':
    for k in range(10):
      for j in range(13):
        dp[i+1][(j*10+k)%13] = (dp[i+1][(j*10+k)%13] + dp[i][j])%MOD
  else:
    t = int(s[i])
    for j in range(13):
      dp[i+1][(j*10+t)%13] = (dp[i+1][(j*10+t)%13] + dp[i][j])%MOD
print(dp[len(s)][5])