# -*- coding: utf-8 -*-
"""
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0189
AC
"""
import sys
from sys import stdin
input = stdin.readline


def warshallFloyd(V, dp):
    for k in range(V):
        for i in range(V):
            for j in range(V):
                dp_ik = dp[i][k]
                dp_kj = dp[k][j]
                if dp[i][j] > dp_ik + dp_kj:
                    dp[i][j] = dp_ik + dp_kj


def main(args):
    while True:
        n_max = 9+1
        n = int(input())
        if n == 0:
            break
        dp = [[float('inf')] * n_max for _ in range(n_max)]
        for i in range(n_max):
            dp[i][i] = 0

        max_town = 0
        for _ in range(n):
            a, b, c = map(int, input().split())
            dp[a][b] = c
            dp[b][a] = c
            max_town = max(max_town, a, b)

        warshallFloyd(max_town + 1, dp)


        min_dist = float('inf')
        town_live = -1
        for i, d in enumerate(dp[:max_town+1]):
            sum_dist = 0
            for ele in d[:max_town+1]:
                sum_dist += ele
            if sum_dist < min_dist:
                min_dist = sum_dist
                town_live = i

        print('{} {}'.format(town_live, min_dist))



if __name__ == '__main__':
    main(sys.argv[1:])
    