s=input()
n=len(s)
dp=[13*[0]for _ in range(n)]
if s[0]=="?":dp[0]=10*[1]+[0]*3
else:dp[0][int(s[0])]+=1
for i in range(1,n):
  if s[i]!="?":
    for j in range(13):
      dp[i][(j*10+int(s[i]))%13]=dp[i-1][j]
  else:
    for j in range(13):
      for k in range(10):
        dp[i][(j*10+k)%13]+=dp[i-1][j]
  for j in range(13):dp[i][j]%=10**9+7
print(dp[-1][5])