# coding: utf-8

import sys
input = sys.stdin.readline

bit = lambda s, j: (s >> j) & 1

def f(n, a):
    mod = int(1e9 + 7)
    sn = 1 << n
    dp = [[0] * sn for _ in range(n + 1)]
    dp[0][0] = 1
    for i in range(n):
        dpi = dp[i]
        dpi1 = dp[i + 1]
        ai = a[i]
        for s in range(0, sn):
            if dpi[s]:
                for j in range(n):
                    if bit(s, j) == 0 and ai[j]:
                        s_ = s | 1 << j
                        dpi1[s_] += dpi[s]
                        if dpi1[s_] > mod:
                            dpi1[s_] -= mod
    return(dp[-1][-1])

n = int(input()) # 1 <= n <= 21
a = [list(map(int, input().split())) for _ in range(n)]
print(f(n, a))
