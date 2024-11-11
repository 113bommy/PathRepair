n,k=map(int, input().split())
a=list(map(int, input().split()))
dp=[0]*n
for i in range(1,n):
    m=10**5
    for j in range(max(0,i-k),i):
        m=min(m,dp[j]+abs(a[j]-a[i]))
    dp[i]=m
print(dp[-1])