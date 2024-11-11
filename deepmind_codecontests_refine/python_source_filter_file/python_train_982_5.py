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
created by shhuan at 2020/1/8 21:47

"""


def bit(val, n, l):
    x = []
    while val > 0:
        x.append(val % n)
        val //= n
    return [0] * (l - len(x)) + x[::-1]


def solve(N, K, D):
    if math.log(N, K) > D or K ** D < N:
        print(-1)
        return
    a = []
    for i in range(1, N+1):
        x = bit(i, K, D)
        a.append(x)
    ans = []
    for d in range(D):
        ans.append(' '.join(map(str, [a[i][d] + 1 for i in range(N)])))

    print('\n'.join(ans))


N, K, D = map(int, input().split())
solve(N, K, D)