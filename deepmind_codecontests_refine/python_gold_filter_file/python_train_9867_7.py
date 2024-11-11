a,b,c,d=map(int,input().split())
mod=998244353
dp=[(d+1)*[0]for _ in range(c+1)]
for i in range(a,c+1):
  for j in range(b,d+1):
    if i==a and j==b:
      dp[i][j]=1
      continue
    if i==a:
      dp[i][j]=dp[i][j-1]*i%mod
      continue
    if j==b:
      dp[i][j]=dp[i-1][j]*j%mod
      continue
    dp[i][j]=(dp[i-1][j]*j+dp[i][j-1]*i-dp[i-1][j-1]*(i-1)*(j-1))%mod
print(dp[c][d])
