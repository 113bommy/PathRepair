n=int(input())
p=tuple(map(float,input().split()))
dp=[[0.0]*(n+1) for _ in range(n+1)]
dp[0][0]=1.0
for i in range(1,n+1):
  for j in range(i+1):
    dp[i][j]=dp[i-1][j]*(1-p[i-1])
    if j>0:
      dp[i][j]+=dp[i-1][j-1]*p[i-1]
print(sum(dp[n][n//2+1:]))