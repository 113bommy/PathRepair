mod = 10**9+7
s=[x for x in input()]
n=len(s)
dp=[[0 for i in range(13)] for j in range(n+1)]
dp[0][0]=1
for i in range(n):
  for j in range(10):
    if s[i]!='?' and s[i]!=str(j):
      continue
    for k in range(13):
      dp[i+1][(k*10+j)%13] += dp[i][k]
  for j in range(13):
    dp[i+1][j]=dp[i+1][j]%mod
print(dp[n][5])