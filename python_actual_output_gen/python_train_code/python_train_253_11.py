n,k=map(int,input().split())
li=[int(K) for K in input().split()]
dp=[[0 for j in range(k+1)] for i in range(n+1)]
dp[0][0]=1
for b in range(1,n+1):
  dp[b][0]=1
mod=10**9+7  
for i in range(1,n+1):
  sums=[0]*(k+1)
  sums[0]=1
  for j in range(1,k+1):
    sums[j]=sums[j-1]+dp[i-1][j]
  for a in range(k+1):
    res=sums[a]
    if(a-li[i-1]-1)>=0:
      res=(res-sums[a-li[i-1]-1]+mod)%mod
    dp[i][a]=res
print(dp[n][k])    
