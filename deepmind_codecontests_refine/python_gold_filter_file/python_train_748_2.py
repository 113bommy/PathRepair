n=int(input())
p=[0]+list(map(int,input().split()))
dp=[[[10**18]*2 for i in range(n//2+1)] for j in range(n+1)]
dp[0][0][0]=dp[0][0][1]=0
for i in range(1,n+1):
  if p[i]==0:
    for j in range(1,n//2+1):
      dp[i][j][0]=min(dp[i-1][j-1][0],dp[i-1][j-1][1]+1)
    for j in range(n//2+1):
      dp[i][j][1]=min(dp[i-1][j][0]+1,dp[i-1][j][1])
  else:
    if p[i]%2==0:
      for j in range(1,n//2+1):
        dp[i][j][0]=min(dp[i-1][j-1][0],dp[i-1][j-1][1]+1)
    else:
      for j in range(n//2+1):
        dp[i][j][1]=min(dp[i-1][j][0]+1,dp[i-1][j][1])
print(min(dp[-1][-1]))