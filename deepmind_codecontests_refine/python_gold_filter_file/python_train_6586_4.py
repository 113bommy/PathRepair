#!/usr/bin/env python3
import sys
input = sys.stdin.readline
INF = 10**5

n = int(input())
a_raw = [int(item) for item in input().split()]
a = []
cnt = 0
for item in a_raw:
    if item >= n:
        cnt += 1
    else:
        a.append(item)

nn = len(a)
dp = [[INF] * n for _ in range(nn+1)]
# dp[i-th item][height] : min score
dp[0][0] = cnt
for i, item in enumerate(a):
    for j in range(n):
        if dp[i][j] == INF:
            continue
        if item > j:
            # Skip
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1)
        # Use
        dp[i+1][item] = min(dp[i+1][item], dp[i][j] + max(0, item - j))

print(min(dp[-1]))