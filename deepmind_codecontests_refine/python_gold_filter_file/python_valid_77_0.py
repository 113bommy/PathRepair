n, mod = map(int, input().split())
dp = [0]*(n+1)
dp[-1] = 1
for i in range(n-1, 0, -1):
    dp[i] = (dp[i+1] + dp[i+1]) % mod
    for j in range(2, n//i+1):
        dp[i] = (dp[i] + dp[i*j] - (dp[i*j+j] if i*j+j <= n else 0)) % mod
print((dp[1]-dp[2]) % mod)
