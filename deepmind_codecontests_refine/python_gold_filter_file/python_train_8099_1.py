n = int(input())
dp = [[0] * 4 for i in range(n + 2)]
for i in range(4):
    dp[2][i] = 1
mod = 10**9 + 7
for i in range(3, n + 2):
    for j in range(4):
        for k in range(4):
            dp[i][j] += dp[i - 1][k]
    dp[i][2] -= dp[i - 2][0]
    dp[i][2] -= dp[i - 2][1]
    dp[i][1] -= dp[i - 2][0] - dp[i - 3][1]
    dp[i][2] -= 3 * dp[i - 3][0]
print(sum(dp[-1]) % mod)
