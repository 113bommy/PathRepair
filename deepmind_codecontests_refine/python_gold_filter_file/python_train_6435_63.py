# coding: utf-8

import sys
input = sys.stdin.readline

mod = int(1e9 + 7)

def f(K, D):
    l = len(K)
    dp = [[[0] * D for _ in range(2)] for _ in range(l + 1)]
    dp[0][0][0] = 1
    for i in range(l):
        ki = int(K[i])
        for j in range(2):
            uki = 9 if j else ki
            dpij = dp[i][j]
            for d in range(D):
                for k in range(uki + 1):
                    dpij_ = dp[i + 1][j or k < ki]
                    d_ = (d + k) % D
                    dpij_[d_] += dpij[d]
                    dpij_[d_] %= mod
    # K = 0 の場合が含まれるので -1
    return((dp[-1][0][0] + dp[-1][1][0] - 1 + mod) % mod)

K = input().rstrip() # 1 <= K <= 10^10000
D = int(input()) # 1 <= D <= 100

print(f(K, D))
