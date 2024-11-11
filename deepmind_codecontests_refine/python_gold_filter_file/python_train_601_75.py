n, m = map(int, input().split())
s = list(map(int, input().split()))
t = list(map(int, input().split()))
mod = 10**9 + 7

dp = [[1] * (m+1) for _ in range(n+1)]

for i in range(n):
    for j in range(m):
        dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] - dp[i][j]
        dp[i+1][j+1] %= mod
        if s[i] == t[j]:
            dp[i+1][j+1] += dp[i][j]
            dp[i+1][j+1] %= mod

print(dp[n][m])
