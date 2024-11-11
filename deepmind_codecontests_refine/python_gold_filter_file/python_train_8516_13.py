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
def slv(N, S, Q, K):

    for k in K:
        d = 0
        m = 0
        dm = 0
        ans = 0
        for i in range(N):
            if S[i] == 'D':
                d += 1
            elif S[i] == 'M':
                m += 1
                dm += d
            elif S[i] == 'C':
                ans += dm

            j = i-k+1
            if j < 0:
                continue

            if S[j] == 'D':
                d -= 1
                dm -= m
            elif S[j] == 'M':
                m -= 1
        print(ans)


def main():
    N = read_int()
    S = read_str()
    Q = read_int()
    K = read_int_n()
    (slv(N, S, Q, K))


if __name__ == '__main__':
    main()
