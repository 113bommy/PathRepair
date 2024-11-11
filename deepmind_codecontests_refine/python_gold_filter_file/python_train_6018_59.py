s=input()
n=len(s)
dp=[13*[0]for _ in range(n+1)]
dp[0][0]=1
mod=10**9+7
for i in range(1,n+1):
  if s[i-1]=="?":
    for j in range(13):
      for k in range(10):
        m=(j*10+k)%13
        dp[i][m]+=dp[i-1][j]
        dp[i][m]%=mod
  else:
    for j in range(13):
      m=(j*10+int(s[i-1]))%13
      dp[i][m]+=dp[i-1][j]
      dp[i][m]%=mod
print(dp[-1][5])