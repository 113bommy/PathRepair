mod=10**9+7
s=input()
dp=[[0]*13 for _ in range(len(s)+1)]
dp[0][0]=1
r=[i%13 for i in range(130)]

for i in range(len(s)):
  if s[i]=='?':
    for j in range(13):
      for k in range(10):
        dp[i+1][r[j*10+k]]+=dp[i][j]
  else:
    t = int(s[i])
    for j in range(13):
      dp[i+1][r[j*10+t]] += dp[i][j]

  for k in range(13):
    dp[i+1][k] %= mod

print(dp[len(s)][5])