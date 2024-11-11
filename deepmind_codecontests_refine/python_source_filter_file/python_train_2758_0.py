# -*- coding:utf-8 -*-

"""

created by shuangquan.huang at 1/9/20

"""

import collections
import time
import os
import sys
import bisect
import heapq
from typing import List


def check(H, N, K):
    for i in range(K+1, N-K+1):
        h = H[i]
        for j in range(K+1):
            if h <= 0:
                break
            if i - j >= 0:
                h = min(h, H[i-j] - (K - j))
            if i + j <= N:
                h = min(h, H[i + j] - (K - j))
        if h > 0:
            return False
    return True


def solve2(N, A):
    A = [0] + A + [0]
    lo, hi = 0, N // 2 + 1
    while lo <= hi:
        k = (lo + hi) // 2
        if check(A, N, k):
            hi = k - 1
        else:
            lo = k + 1
    return lo
    

def solve(N, A):
    A = [0] + A + [0]
    H = [N] * (N+2)
    H[0] = H[-1] = 0
    worst = 0
    for i in range(1, N+1):
        worst = min(worst, A[i] - i)
        H[i] = i + worst
        # k = min([A[i-j] + j for j in range(i+1)])
        # H[i] = min(H[i], k)
    worst = N+1
    for i in range(N, 0, -1):
        worst = min(worst, A[i] + i)
        H[i] = min(H[i], worst - i)
        # k = min([A[i+j] + j for j in range(N-i+1)])
        # H[i] = min(H[i], k)
    print(H)
    return max(H)
    
    
    

# import random
# N = 10 ** 5
# A = [random.randint(0, 10**9) for _ in range(N)]
# t0 = time.time()
# print('starting...')
# solve(N, A)
# print(time.time() - t0)
# N = 10**5
# A = [i+1 for i in range(N)] + [N+1] + [N-i for i in range(N)]
# t0 = time.time()
# print(solve(2*N+1, A))
# print(time.time() - t0)

N = int(input())
A = [int(x) for x in input().split()]
print(solve(N, A))