def add_self(i, j, x):
    dp[i][j] += dp[x][j]
    if dp[i][j] > m:
        dp[i][j] -= m
n, k, d = map(int, input().split())
m = 1000000007
dp = [[[0, 1][i == 1 and j != 0] for j in range(k + 1)] for i in range(n + 1)]
for i in range(2, n + 1):
    for j in range(1, k + 1):
        if i <= j:
            dp[i][j] = (1 << i - 1) % m
        else:
            for x in range(i - j, i):
                add_self(i, j, x)
print(dp[n][k] - dp[n][d - 1])