n, m = map(int, input().split())
s = list(map(int, input().split()))
t = list(map(int, input().split()))
mod = 10 ** 9 + 7

dp = [[0] * (m + 1) for _ in range(n + 1)]

for i, ei in enumerate(s, 1):
    for j, ej in enumerate(t, 1):
        if ei == ej:
            dp[i][j] = dp[i-1][j] + dp[i][j-1] + 1
        else:
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]

        dp[i][j] %= mod

ans = dp[n][m] + 1
ans %= mod
print(ans)
