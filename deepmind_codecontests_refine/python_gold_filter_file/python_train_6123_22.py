import sys
import re
import math
import collections
import decimal
import bisect
import itertools
import fractions
import functools
import copy
import heapq
import decimal
import statistics
import queue

# import numpy as np

sys.setrecursionlimit(10 ** 9)
INF = 10 ** 16
MOD = 10 ** 9 + 7
# MOD = 998244353

ni = lambda: int(sys.stdin.readline())
ns = lambda: map(int, sys.stdin.readline().split())
na = lambda: list(map(int, sys.stdin.readline().split()))


# ===CODE===

def main():
    n = ni()
    e = [[] for _ in range(n)]
    for _ in range(n - 1):
        x, y = ns()
        x -= 1
        y -= 1
        e[x].append(y)
        e[y].append(x)

    # dp[i][0]:i番目のノードが白のときの組み合わせの数
    # dp[i][1]:i番目のノードが黒のときの組み合わせの数
    dp = [[1, 1] for _ in range(n)]
    visited = [False for _ in range(n)]

    def dfs(vi, prnt):
        if visited[vi]:
            return
        visited[vi] = True

        for chld in e[vi]:
            if chld == prnt:
                continue
            dfs(chld, vi)

            # 親が白なら子は白でも黒でもいい
            dp[vi][0] *= dp[chld][0] + dp[chld][1]
            dp[vi][0] %= MOD
            # 親が黒田と子は白じゃないとダメ
            dp[vi][1] *= dp[chld][0]
            dp[vi][1] %= MOD

    dfs(0, -1)
    print((dp[0][0] + dp[0][1]) % MOD)


if __name__ == '__main__':
    main()
