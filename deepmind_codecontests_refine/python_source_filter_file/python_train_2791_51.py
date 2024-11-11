n,k=map(int,input().split())
h=list(map(int,input().split()))
h+=[0]*k
inf=10**7
dp=[inf]*(n+k)
dp[0]=0
for i in range(n):
    for j in range(1,k+1):
        dp[i+j]=min(dp[i]+abs(h[i]-h[i+j]),dp[i+j])
print(dp[n-1])
