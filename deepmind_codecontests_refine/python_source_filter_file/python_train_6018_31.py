S=input()
dp=[[0]*13 for i in range(len(S)+1)]
dp[0][0]=1
mod=10**9+7
for i in range(len(S)):
  if(S[i]=='?'):
    for j in range(13):
      for k in range(10):
        dp[i+1][(j*10+k)%13]=(dp[i+1][(j*10+k)%13]+dp[i][j])%mod
  else:
    k=int(S[i])
    for j in range(13):
      dp[i+1][(j*10+k)%13]=(dp[i+1][(j*10+k)%13]+dp[i][j])%mod
print(dp[len(S)][5])