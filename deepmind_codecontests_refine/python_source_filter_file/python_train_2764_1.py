n,x,y=map(int,input().split())
dp = [0.]*(n+1)
for i in range(1,n+1):
    dp[i]=min(dp[i-1]+x,dp[(i+1)//2]+y+(x*(i&1)))
print(dp[n])
