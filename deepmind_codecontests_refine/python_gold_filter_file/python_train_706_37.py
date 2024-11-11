n,k=map(int,input().split())
a=list(map(int,input().split()))
mod=10**9+7
dp=[0]*(k+1)
for i in range(a[0]+1):
    dp[i]=1
for i in range(1,n):
    u=a[i]
    h=dp[:]
    for j in range(u+1,k+1):
        h[j]=(dp[j]-dp[j-u-1])%mod
    for j in range(1,k+1):
        h[j]=(h[j]+h[j-1])%mod
    dp=h
print(dp[k])