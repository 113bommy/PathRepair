# -*- coding: utf-8 -*-

import math
import collections
import bisect
import heapq
import time
import random
import itertools
import sys
from typing import List

"""
created by shhuan at 2020/3/19 14:23

"""


def solve(N, A):
    if sum(A) < N:
        return -1
    nb = 20
    needs = [0 for _ in range(nb)]
    for i in range(nb):
        if N & (1 << i):
            needs[i] = 1

    have = [0 for _ in range(32)]
    for a in A:
        b = 0
        while a > 0:
            a >>= 1
            b += 1
        have[b - 1] += 1

    ans = 0
    for i in range(nb):
        if have[i] >= needs[i]:
            have[i] -= needs[i]
            have[i+1] += have[i] // 2
        else:
            for j in range(i+1, 32):
                if have[j] > 0:
                    have[j] -= 1
                    for k in range(i, j):
                        have[k] += 1
                    ans += j-i
                    needs[i] = 0
                    break
            if needs[i] > 0:
                return -1

    return ans

T = int(input())
for ti in range(T):
    N, M = map(int, input().split())
    A = [int(x) for x in input().split()]
    print(solve(N, A))
