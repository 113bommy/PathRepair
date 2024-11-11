MOD = 10**9+7
S = input()
l = len(S)
dp = [[0] * 13 for _ in range(l+1)]
dp[0][0] = 1
p = 1
for i in range(l):
  if(S[i] != '?'):
    n = int(S[i])
    for j in range(13):
      dp[i+1][(j*10+n)%13] += dp[i][j]
  else:
    for k in range(10):
      for j in range(13):
        dp[i+1][(j*10+k)%13] += dp[i][j]
  for j in range(13):
    dp[i+1][j] = dp[i+1][j]%MOD
  p = (p*10)%MOD    
print(dp[l][5])