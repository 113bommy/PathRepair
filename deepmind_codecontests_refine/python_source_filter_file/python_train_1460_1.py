#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
input:
4 5
0 0 1 0 0
1 0 0 0 0
0 0 0 1 0
0 0 0 1 0

output:
4
"""
import sys


def solve():
    dp = [[0] * W for _ in range(H)]
    max_width = 0
    # for m in range(H):
    #     for n in range(W):
    #         dp[m][n] = (int(carpet_info[m][n]) + 1) % 2
    #         max_width |= dp[m][n]

    for i in range(1, H):
        for j in range(1, W):
            if not int(carpet_info[i][j]):
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1
                max_width = max(max_width, dp[i][j])
                
    return pow(max_width, 2)


if __name__ == '__main__':
    _input = sys.stdin.readlines()
    H, W = map(int, _input[0].split())
    carpet_info = list(map(lambda x: x.split(), _input[1:]))
    print(solve())