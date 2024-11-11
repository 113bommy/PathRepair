# -*- coding: utf-8 -*-
import bisect
import heapq
import math
import random
import sys
from collections import Counter, defaultdict, deque
from decimal import ROUND_CEILING, ROUND_HALF_UP, Decimal
from functools import lru_cache, reduce
from itertools import combinations, combinations_with_replacement, product, permutations
from operator import add, mul, sub

sys.setrecursionlimit(100000)
input = sys.stdin.readline
INF = 2**62-1

def read_int():
    return int(input())


def read_int_n():
    return list(map(int, input().split()))


def read_float():
    return float(input())


def read_float_n():
    return list(map(float, input().split()))


def read_str():
    return input().strip()


def read_str_n():
    return list(map(str, input().split()))


def error_print(*args):
    print(*args, file=sys.stderr)


def mt(f):
    import time

    def wrap(*args, **kwargs):
        s = time.time()
        ret = f(*args, **kwargs)
        e = time.time()

        error_print(e - s, 'sec')
        return ret

    return wrap


@mt
def slv(N, A):
    ai = [(0, -1)] + [(a, i+1) for i, a in enumerate(A)]
    ai.sort()
    A = [a for a, i in ai]
    I = [i for a, i in ai]
    ans = [0] * (N+1)

    i = N
    same = 0
    q = []
    while i != 0:
        j = i
        while True:
            j -= 1
            if I[j] < I[i]:
                break
            heapq.heappush(q, A[j])
        d = A[i] - A[j]
        ans[I[i]] = d * (same+1)
        same += 1
        while q and q[0] >= A[j]:
            b = heapq.heappop(q)
            ans[I[i]] += b - A[j]
            same += 1
        i = j
    for r in ans[1:]:
        print(r)

def main():
    N = read_int()
    A = read_int_n()
    (slv(N, A))


if __name__ == '__main__':
    main()
