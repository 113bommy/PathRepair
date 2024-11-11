N, K = map(int, input().split())
a = [int(x) for x in input().split()]
mod = 10**9+7
dp = [[0] * (K+1) for i in range(N+1)]
for i in range(K+1):
    dp[0][i] = 1
for i in range(1, N+1):
    for j in range(K+1):
        tmp = 0 if j-a[i-1]-1 < 0 else dp[i-1][j-a[i-1]-1]
        dp[i][j] += dp[i-1][j]-tmp
        dp[i][j] %= mod
    if i != N:
        for j in range(K):
            dp[i][j+1] = (dp[i][j+1]+dp[i][j])%mod
print(dp[N][K])