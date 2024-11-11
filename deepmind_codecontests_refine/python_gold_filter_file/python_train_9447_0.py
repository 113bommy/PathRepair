#!/usr/bin/python3.7

import sys


n, k = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]

cur = 0

def is_submask(n, mask):
    return (n & mask) == mask

def f(mask):
    s = [[False for j in range(n)] for i in range(n)]
    for l in range(n):
        cur = 0
        for r in range(l, n):
            cur += a[r]
            s[l][r] = is_submask(cur, mask)
    dp = [[False for j in range(n)] for i in range(k)]
    dp[0] = s[0][:]
    for k1 in range(1, k):
        for r in range(n):
            for l in range(1, r + 1):
                    dp[k1][r] |= dp[k1 - 1][l - 1] & s[l][r]
    return dp[k - 1][n - 1]

cur = 0
for i in range(56, -1, -1):
    if f(cur + 2 ** i):
        cur += 2 ** i
print(cur)