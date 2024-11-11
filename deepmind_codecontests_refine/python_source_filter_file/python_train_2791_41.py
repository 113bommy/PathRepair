n,k=map(int,input().split())
h=list(map(int,input().split()))
dp=[0]*n
for i in range(1,n):
  dp[i]=dp[i-1]+abs(h[i-1]-h[i])
  for j in range(2,min(k+1,i+1)):
    dp[i]=min(dp[i],dp[i-j]+abs(h[i-j]-h[i]))
print(dp[-1])