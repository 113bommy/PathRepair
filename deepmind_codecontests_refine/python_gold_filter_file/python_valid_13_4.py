#!/usr/bin/env python3
# from typing import *

import sys
import io
import math
import collections
import decimal
import itertools
import bisect
import heapq


def input():
    return sys.stdin.readline()[:-1]

# sys.setrecursionlimit(1000000)

# _INPUT = """8
# 9 10 23
# 2 3 0
# 3 2 3
# 1 2 0
# 2 4 2
# 5 2 2
# 2 17 16
# 2 1 1
# """
# sys.stdin = io.StringIO(_INPUT)

INF = 10**10

YES = 'YES'
NO = 'NO'

def place(N, M, Map):
    T = [[''] * M for _ in range(N)]



    # horizontal
    D1 = 'ab'
    q = []
    if Map[0][0]:
        T[0][0] = D1[0]
        T[0][1] = D1[0]
        q.append((0, 0, 0))
    while q:
        i, j, c = q.pop()
        if i+1 < N and Map[i+1][j] and T[i+1][j] == '':
            T[i+1][j] = D1[1-c]
            T[i+1][j+1] = D1[1-c]
            q.append((i+1, j, 1-c))
        if j+3 < M and Map[i][j+2] and T[i][j+2] == '':
            T[i][j+2] = D1[1-c]
            T[i][j+3] = D1[1-c]
            q.append((i, j+2, 1-c))

    D2 = 'cd'
    q = []
    if not T[N-1][M-1]:
        T[N-2][M-1] = D2[0]
        T[N-1][M-1] = D2[0]
        q.append((N-1, M-1, 0))
    while q:
        i, j, c = q.pop()
        if i-3 >= 0 and not Map[i-2][j] and T[i-2][j] == '':
            T[i-3][j] = D2[1-c]
            T[i-2][j] = D2[1-c]
            q.append((i-2, j, 1-c))
        if j-1 >= 0 and not Map[i][j-1] and T[i][j-1] == '':
            T[i-1][j-1] = D2[1-c]
            T[i][j-1] = D2[1-c]
            q.append((i, j-1, 1-c))


    return [''.join(T[i]) for i in range(N)]

def solve(N, M, K):
    Map = [[False] * M for _ in range(N)]

    if N % 2 == 0:
        if (K % N) % 2 == 0 and math.ceil(K/N) * 2 <= M:
            i, j = 0, 0
            for k in range(K):
                Map[i][j] = True
                Map[i][j+1] = True
                i += 1
                if i == N:
                    i = 0
                    j += 2

            return ['YES', place(N, M, Map)]
            
    else:
        if M % 2 == 1:
            return ['NO']

        if (M//2) % 2 == 0:
            if K >= M//2 and K % 2 == 0:

                for k in range(M//2):
                    Map[0][k*2] = True
                    Map[0][k*2+1] = True
                i, j = 1, 0
                k = M//2
                while k < K:
                    Map[i][j] = True
                    Map[i][j+1] = True
                    Map[i+1][j] = True
                    Map[i+1][j+1] = True
                    k += 2
                    i += 2
                    if i == N:
                        i = 1
                        j += 2

                return ['YES', place(N, M, Map)]

        else:
            if K >= M//2 and K % 2 == 1:

                for k in range(M//2):
                    Map[0][k*2] = True
                    Map[0][k*2+1] = True
                i, j = 1, 0
                k = M//2
                while k < K:
                    Map[i][j] = True
                    Map[i][j+1] = True
                    Map[i+1][j] = True
                    Map[i+1][j+1] = True
                    k += 2
                    i += 2
                    if i == N:
                        i = 1
                        j += 2

                return ['YES', place(N, M, Map)]

    return ['NO']

T0 = int(input())
for _ in range(T0):
    N, M, K = map(int, input().split())
    ans = solve(N, M, K)
    if len(ans) == 1:
        print(ans[0])
    else:
        print(ans[0])
        for i in range(N):
            print(ans[1][i])
    