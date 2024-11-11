mod=10**9+7
[n ,k]=list(map(int, input().split()))
dp=[[0 for _ in range(n+1)] for _ in range(k+1)]
for last in range(1, n+1):
    dp[1][last]=1
for l in range(2, k+1):
    for i in range(1, n+1):
        for j in range(i, n+1, i):
            dp[l][j]=(dp[l][j]+dp[l-1][i])%mod
print(sum(dp[k])%mod)
