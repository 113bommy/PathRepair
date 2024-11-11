n,k=map(int,input().split())
a=list(map(int,input().split()))
mod=10**9+7
dp=[[0 for j in range(k+1)] for i in range(n+1)]
dp[0][0]=1
for i in range(1,n+1):
    r=[0]*(k+2)
    for j in range(1,k+2):
        r[j]=(r[j-1]+dp[i-1][j-1])%mod
    for j in range(k+1):
        dp[i][j]=(r[j+1]-r[max(0,j-a[i-1])])%mod
print(dp[n][k]%mod)