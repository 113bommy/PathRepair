n, k, d = map(int, input().split())

dp = [[0 for i in range(2)] for j in range(n + 10)]
dp[0][0] = 1
MOD = int(1e9) + 7

for i in range(1, n + 1):
    for j in range(1, min(d - 1, n) + 1):
        dp[i][0] += dp[i - j][0] % MOD

    for j in range(1, min(d - 1, n) + 1):
        dp[i][1] += dp[i - j][1] % MOD

    for j in range(d, min(n, k) + 1):
        dp[i][1] += (dp[i - j][0] + dp[i - j][1]) % MOD

print(dp[n][1] % MOD)
