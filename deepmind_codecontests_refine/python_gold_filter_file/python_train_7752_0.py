#!/usr/bin/python3

from math import sqrt, exp

n = int(input())
k, eps = tuple(map(int, input().split()))
x0, y0 = tuple(map(int, input().split()))
val = []
for _ in range(n):
    x, y = tuple(map(int, input().split()))
    val.append((x - x0)**2 + (y - y0)**2)
#val.sort()

l = 0.0
r = 1e9
cnt = 0
while abs(r - l) > 1e-12 and cnt < 100:
    cnt += 1
    r2 = (r + l) / 2
    p = [exp(1 - d2 / r2) if d2 > r2 else 1.0 for d2 in val]
    dp = [[1.0 ] + [0.0] * k for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, k + 1):
            dp[i][j] = p[i - 1] * dp[i - 1][j - 1] + (1.0 - p[i - 1]) * dp[i - 1][j]
    if 1000 * (1.0 - dp[n][k]) > eps:
        l = r2
    else:
        r = r2

print('%0.9f' % sqrt((r + l) / 2))