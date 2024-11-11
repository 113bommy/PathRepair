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

# _INPUT = """4
# 3 13
# 0 1 2
# 2 777
# 0 4
# 3 255
# 0 1 3
# 10 1000000000
# 0 1 2 3 4 5 6 7 8 9

# """
# sys.stdin = io.StringIO(_INPUT)

INF = 10**10

def solve(N, K, A):
    ans = 0
    A += [20]
    K += 1
    for i in range(N):
        if K <= 10**(A[i+1]-A[i]):
            ans += K*(10**A[i])
            return ans
        else:
            v = (10**(A[i+1]-A[i])-1)
            ans += v*(10**A[i])
            K -= v

    return ans

T0 = int(input())
for _ in range(T0):
    N, K = map(int, input().split())    
    A = list(map(int, input().split()))
    print(solve(N, K, A))