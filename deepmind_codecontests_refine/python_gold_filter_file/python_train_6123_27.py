# coding: utf-8

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

mod = int(1e9 + 7)

def f(r):
    if v[r]:
        return(False)
    v[r] = 1
    dpr = dp[r]
    dpr[0] = 1
    dpr[1] = 1
    for j in e[r]:
        if f(j):
            dpj = dp[j]
            dpr[0] = dpr[0] * (dpj[0] + dpj[1]) % mod
            dpr[1] = dpr[1] * dpj[0] % mod
    return(True)

n = int(input()) # 1 <= n <= 10^5
e = [set() for _ in range(n)]
for x, y in [map(int, input().split()) for _ in range(n - 1)]:
    e[x - 1].add(y - 1)
    e[y - 1].add(x - 1)
v = [0] * n
dp = [[0] * 2 for _ in range(n)]
f(0)
print((dp[0][0] + dp[0][1]) % mod)
