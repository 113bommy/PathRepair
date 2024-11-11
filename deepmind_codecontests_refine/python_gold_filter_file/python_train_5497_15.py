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


class Mod:
    def __init__(self, m):
        self.m = m

    def add(self, a, b):
        return (a + b) % self.m

    def sub(self, a, b):
        return (a - b) % self.m

    def mul(self, a, b):
        return ((a % self.m) * (b % self.m)) % self.m

    def div(self, a, b):
        return self.mul(a, pow(b, self.m-2, self.m))

    def pow(self, a, b):
        return pow(a, b, self.m)


@mt
def slv(N, K):
    r = set([0])
    for i in range(1, math.floor(math.sqrt(N))+1):
        r.add(N//i)
        r.add(i)
    r = list(r)
    r.sort()
    # print(r)

    m = {}
    for i in range(len(r)-1):
        m[i+1] = r[i+1]-r[i]
    DP1 = {k: v for k, v in m.items()}
    DP2 = {}
    M = Mod(10**9+7)
    for _ in range(K):
        S = [0]
        for k in range(1, len(DP1)+1):
            S.append(M.add(S[-1], DP1[k]))
        for k in DP1:
            DP2[k] = M.mul(S[len(DP1)-k+1], m[k])
        DP1, DP2 = DP2, DP1
        # print(DP1)

    ans = 0
    for v in DP2.values():
        ans = M.add(ans, v)
    return ans


def main():
    N, K = read_int_n()
    print(slv(N, K))


if __name__ == '__main__':
    main()
