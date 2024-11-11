n,k=map(int,input().split())
P=list(map(int,input().split()))
dp=[0]*(n+1)
for i in range(n):
    dp[i+1]=dp[i]+P[i]
ma=0
for i in range(1,n-k+1):
    ma=max(ma,dp[i+k]-dp[i])
print((ma+k)/2)