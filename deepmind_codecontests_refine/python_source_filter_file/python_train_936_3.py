# -*- coding: utf-8 -*-
"""
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_F&lang=jp

"""
import sys
from sys import stdin
from collections import namedtuple
input = stdin.readline


def solve(items, W, max_v):
    # ??¨???????????????????????????????????????
    n = len(items)
    dp = [[float('inf')]*(n*max_v + 1) for _ in range(n+1)] #  ?¨??????? ??§????????? ????¨????
    dp[0][0] = 0

    for i, item in enumerate(items):
        for j in range(n * max_v):
            if j < item.v:
                dp[i+1][j] = dp[i][j]
            else:
                dp[i+1][j] = min(dp[i][j], dp[i][j-item.v]+item.w)

    for j in range(n * max_v):
        if dp[n][j] <= W:
            result = j
    return result


item = namedtuple('item', ['v', 'w'])
def main(args):
    N, W = map(int, input().split())
    items = []
    for _ in range(N):
        v, w = map(int, input().split())
        items.append(item(v, w))
    items.sort()
    max_v = items[-1].v

    result = solve(items, W, max_v)
    print(result)


if __name__ == '__main__':
    main(sys.argv[1:])