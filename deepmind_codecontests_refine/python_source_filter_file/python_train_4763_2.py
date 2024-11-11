# -*- coding: utf-8 -*-
import bisect
import heapq
import math
import random
import sys
from collections import Counter, defaultdict
from decimal import ROUND_CEILING, ROUND_HALF_UP, Decimal
from functools import lru_cache, reduce
from itertools import combinations, combinations_with_replacement, product, permutations

sys.setrecursionlimit(10000)


def read_int():
    return int(input())


def read_int_n():
    return list(map(int, input().split()))


def read_float():
    return float(input())


def read_float_n():
    return list(map(float, input().split()))


def read_str():
    return input()


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
def slv(N, K, S):
    error_print('------')
    for s in S:
        error_print(s)
    

    ans = []
    for i, (p, c) in enumerate(zip(S[0], S[1])):
        if c != 0 and p == c:
            ans.append((c , 1, i+1))
            S[1][i] = 0

    for i, (p, c) in enumerate(zip(S[3], S[2])):
        if c != 0 and p == c:
            ans.append((c , 4, i+1))
            S[2][i] = 0


    while len(ans) <= 20000 and sum(S[1]) + sum(S[2]) != 0:
        error_print('------')
        m = len(ans)
        for s in S:
            error_print(s)

        S1 = [c for c in S[1]]
        S2 = [c for c in S[2]]
        for i in range(N):
            c = S[1][i]
            if i == 0:
                if c != 0 and S[2][0] == 0:
                    ans.append((c, 3, i+1))
                    S1[i] = 0
                    S2[i] = c
            else:
                if c != 0 and S[1][i-1] == 0:
                    ans.append((c, 2, i))
                    S1[i] = 0
                    S1[i-1] = c
        for i in range(0, N)[::-1]:
            c = S[2][i]
            if i == N-1:
                if c != 0 and S[1][0] == 0:
                    ans.append((c, 2, i+1))
                    S2[i] = 0
                    S1[i] = c
            else:
                if c != 0 and S[2][i+1] == 0:
                    ans.append((c, 3, i+2))
                    S2[i] = 0
                    S2[i+1] = c
        S[1] = S1
        S[2] = S2
        for i, (p, c) in enumerate(zip(S[0], S[1])):
            if c != 0 and p == c:
                ans.append((c , 1, i+1))
                S[1][i] = 0

        for i, (p, c) in enumerate(zip(S[3], S[2])):
            if c != 0 and p == c:
                ans.append((c , 4, i+1))
                S[2][i] = 0
        
        if len(ans) == m:
            break

    if len(ans) > 20000:
        return -1
    
    if sum(S[1]) + sum(S[2]) != 0:
        return -1
    

    error_print('------')
    for s in S:
        error_print(s)

    return str(len(ans)) + '\n' + '\n'.join(map(lambda x: ' '.join(map(str, x)), ans))

def main():
    N, K = read_int_n()
    S = [read_int_n() for _ in range(4)]
    print(slv(N, K, S))


if __name__ == '__main__':
    main()
