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
import functools
import operator as op

"""
created by shhuan at 2020/1/13 21:43

"""


MOD = 1000000007
MAXN = 10 ** 6 + 5
factorial = [0 for _ in range(MAXN)]
factorial[0] = 1
for i in range(1, MAXN):
    factorial[i] = factorial[i - 1] * i % MOD


def pow(a, b):
    if b == 0:
        return 1

    c = b // 2
    d = pow(a, c)
    if b % 2 == 0:
        return d * d % MOD
    return d * d * b % MOD


def inverse(k):
    return pow(k, MOD-2)


def ncr(n, k):
    k = min(k, n - k)
    return (factorial[n] * inverse(factorial[k]) % MOD) * inverse(factorial[n-1]) % MOD


def dlen(val):
    s = 0
    while val > 0:
        s += 1
        val //= 10

    return s


def gen(index, nbit, pre, a, b):
    if index >= nbit:
        return [pre]

    return gen(index + 1, nbit, pre * 10 + a, a, b) + gen(index + 1, nbit, pre * 10 + b, a, b)


def count(lo, hi, a, b, n, nnum):
    d = b - a
    ans = 0
    for v in gen(0, n, 0, a, b):
        if v < lo or v > hi:
            continue
        u = v - a * nnum
        if u % d == 0:
            y = u // d
            x = nnum - y
            # print(x, y, countab(lo, hi, a, b, x, y, n))
            # ans += countab(lo, hi, a, b, x, y, n)
            ans += ncr(nnum, x)
            # print(x, y, ncr(nnum, x))
            ans %= MOD
    return ans


def solve(N, A, B):
    lo, hi = N * A, N * B
    nl, nh = dlen(lo), dlen(hi)

    if nl == nh:
        return count(lo, hi, A, B, nl, N)
    else:
        return count(lo, 10 ** nl - 1, A, B, nl, N) + count(10 ** nl, hi, A, B, nh, N)


def test():
    N = 10 ** 6
    A = random.randint(1, 5)
    B = random.randint(1, 4) + A
    t0 = time.time()
    print(solve(N, A, B))
    print(time.time() - t0)

# print(solve(10**6, 2, 3))

A, B, N = map(int, input().split())
print(solve(N, A, B))