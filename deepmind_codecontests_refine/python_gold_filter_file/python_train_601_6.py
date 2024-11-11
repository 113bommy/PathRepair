#!/usr/bin/env python3

MOD = 10**9 + 7

n, m = map(int, input().split())
s = list(map(int, input().split()))
t = list(map(int, input().split()))

dp = [[0] * (m + 1) for _ in range(n + 1)]
dp[0][0] = 0
for i in range(n):
    for j in range(m):
        dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] - dp[i][j]
        if s[i] == t[j]:
            dp[i + 1][j + 1] += dp[i][j] + 1
        dp[i + 1][j + 1] %= MOD

print(dp[n][m] + 1)
