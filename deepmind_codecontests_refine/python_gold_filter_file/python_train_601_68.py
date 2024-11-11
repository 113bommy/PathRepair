n, m = map(int, input().split())
s = list(map(int, input().split()))
t = list(map(int, input().split()))
mod = 10 ** 9 + 7

dp = [[0] * (m + 1) for _ in range(n + 1)]
for i in range(n + 1):
    dp[i][0] = 1
for j in range(m + 1):
    dp[0][j] = 1


for i, es in enumerate(s, 1):
    for j, et in enumerate(t, 1):
        if es == et:
            dp[i][j] = dp[i-1][j] + dp[i][j-1]
        else:
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]

        dp[i][j] %= mod

ans = dp[n][m]
print(ans)
