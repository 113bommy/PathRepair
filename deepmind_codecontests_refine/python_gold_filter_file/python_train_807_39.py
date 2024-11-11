n,*a=map(int,open(0).read().split())
a=sorted([(j,i) for i,j in enumerate(a)])[::-1]
dp=[[-1]*(n+1) for _ in range(n+1)]
dp[0][0]=0
for m,(a_k,k) in enumerate(a):
  for i in range(m+1):
    j=m-i
    dp[i+1][j]=max(dp[i+1][j],dp[i][j]+a_k*abs(k-i))
    dp[i][j+1]=max(dp[i][j+1],dp[i][j]+a_k*abs(k-((n-1)-j)))
ans=0
for i in range(n+1):
  ans=max(ans,dp[i][n-i])
print(ans)