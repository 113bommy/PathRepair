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

# _INPUT = """5 2
# 5 2 3
# 3 1 4 5 2
# 3 5
# """
# sys.stdin = io.StringIO(_INPUT)

INF = 10**20

def calc(i1, i2):
    n = i2 - i1 - 1
    if n == 0:
        return 0

    cost1 = INF
    if n >= K:
        cost1 = (n//K) * X + (n%K) * Y
    else:
        if max(A[i1+1:i2]) < max(A[i1], A[i2]):
            cost1 = n*Y

    cost2 = INF
    if max(A[i1+1:i2]) < max(A[i1], A[i2]):
        cost2 = n*Y
    else:
        if n >= K:
            cost2 = (N-K)*Y + X

    return min(cost1, cost2)

def solve():
    i = 1
    i0 = 0
    j = 0
    cost = 0
    while i < N:
        if A[i] == B[j]:
            cost += calc(i0, i)
            i0 = i
            j += 1
            if j == M:
                break

        i += 1

    if j < M:
        return -1

    if i0 < N-1:
        cost += calc(i0, N-1)
    
    if cost >= INF:
        return -1
    else:
        return cost

N, M = map(int, input().split())
X, K, Y = map(int, input().split())
A = [-INF] + list(map(int, input().split())) + [-INF]
B = list(map(int, input().split()))
N += 2

print(solve())

