n,k,*h=map(int,open(0).read().split())
dp=[10**18]*(n+k+1)
h=h+[0]*k
dp[0]=0
for i in range(n):
  for j in range(k):
    dp[j+i+1]=min(dp[i],dp[i+j+1]+abs(h[i+j+1]-h[i]))
print(dp[n-1])