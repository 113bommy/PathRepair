n,a,*x=map(int,open(0).read().split())
x=[0]+x
dp=[[[0]*(50*n+1)for j in range(n+1)]for i in range(n+1)]
dp[0][0][0]=1
for i in range(1,n+1):
  dp[i][0]=dp[i-1][0]
  for j in range(1,n+1):
    for k in range(1,50*n+1):
      dp[i][j][k]=dp[i-1][j][k]
      if k-x[i]>=0:
        dp[i][j][k]+=dp[i-1][j-1][k-x[i]]
ans=0
for i in range(1,n+1):
  j=i*a
  if j<50*n+2:
    ans+=dp[-1][i][j]
print(ans)