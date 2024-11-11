N,K=map(int,input().split())
a=list(map(int,input().split()))
dp=[[0]*(K+1) for i in range(N)]
for j in range(a[0]+1):
  dp[0][j]=1
  
for i in range(1,N):
  for j in range(1,K+1):
    if j==0:
      dp[i][j]=1
    else:
      dp[i][j]=dp[i][j-1]+dp[i-1][j]
      if j>=a[i]+1:
        dp[i][j]-=dp[i-1][j-1-a[i]]
      dp[i][j]=dp[i][j]%(10**9+7)
      
print(dp[-1][-1])