mod=10**9+7
s=input()
n=len(s)
dp=[13*[0]for _ in range(n)]
if s[0]=="?":dp[0]=[1]*10+[0]*3
else:dp[0][int(s[0])]=1
for i in range(1,n):
  for j in range(13):
    if s[i]=="?":
      for k in range(10):
        dp[i][(10*j+k)%13]+=dp[i-1][j]
        dp[i][(10*j+k)%13]%=mod
    else:
      dp[i][(10*j+int(s[i]))%13]+=dp[i-1][j]
      dp[i][(10*j+int(s[i]))%13]%=mod
print(dp[-1][5])