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

# _INPUT = """1
# 5 1
# 1 2 4 5 3
# """
# sys.stdin = io.StringIO(_INPUT)

INF = 10**10

def solve(N, M, P):
    T = []
    K = dict()
    for i in range(N):
        v = (i - P[i]) % N
        T.append(v)
        K[v] = (i - P[i]) % N

    counter = collections.Counter(T)
    result = []
    for v, n in counter.items():
        if n >= N - 2*M:
            k = K[v]

            swap_count = 0
            P1 = list(P)
            D1 = {v: i for i, v in enumerate(P1)}
            for i in range(N):
                a = (i - k) % N
                if P1[i] != a:
                    swap_count += 1
                    j = D1[a]
                    D1[P[j]], D1[P[i]] = D1[P[i]], D1[P[j]]
                    P1[i], P1[j] = P1[j], P1[i]
            if swap_count <= M:
                result.append(k)

    result.sort()
    return [len(result)] + result


T0 = int(input())
for _ in range(T0):
    N, M = map(int, input().split())
    P = list(map(lambda x: int(x)-1, input().split()))
    print(*solve(N, M, P))
