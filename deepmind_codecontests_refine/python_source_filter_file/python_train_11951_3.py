#!/usr/bin/env python3
import sys
input = sys.stdin.readline
MOD = 10**9 + 7
INF = 10**13

n, K = [int(item) for item in input().split()]
h = [0] + [int(item) for item in input().split()]

# dp[i][j][k] i:till ith, j:skipped j, k: previous index
dp = [[[INF] * (n + 1) for _ in range(n + 1)] for _ in range(n + 1)]
for i, item in enumerate(h):
    if i == 0:
        dp[0][0][0] = 0
        continue
    for j in range(n-1, -1, -1):
        for k in range(n-1, -1, -1):
            if dp[i-1][j][k] == INF:
                continue
            # skip
            dp[i][j+1][k] = min(dp[i][j+1][k], dp[i-1][j][k])
            # use
            dp[i][j][i] = min(dp[i][j][i], dp[i-1][j][k] + max(0, h[i] - h[k]))
            
ans = INF
for j in range(n):
    ans = min(ans, dp[n][K][j+1])

print(ans)