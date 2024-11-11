n,k=map(int,input().split())
p=list(map(int,input().split()))
dp=[0]*(n-k+1)
dp[0]=sum(p[:k])
print(p)
for i in range(n-k):
    dp[i+1]=dp[i]+p[k+i]-p[i]
print((max(dp)+k)/2)