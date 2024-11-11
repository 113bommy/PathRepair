S = input()[::-1]
l = len(S)
dp = [[0]*2 for _ in range(l+1)]
for i in range(l):
  dp[i+1][0]=min(dp[i][0]+int(s[i]),dp[i][1]+int(s[i])+1)
  if i!=0:
    dp[i+1][1]=min(dp[i][0]+10-int(s[i]),dp[i][1]+10-(int(s[i])+1))
  else:
    dp[i+1][1]=dp[i][0]+10-int(s[i])
print(min(dp[-1][0],dp[-1][1]+1))