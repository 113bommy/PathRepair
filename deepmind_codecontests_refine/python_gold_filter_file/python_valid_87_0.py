#!/usr/local/bin/python3

import bisect
import collections
import functools
import heapq
import itertools
import math
import random
import sys
import time
input = sys.stdin.readline
# sys.setrecursionlimit(500005)
def ri(): return int(input())
def rf(): return list(map(float, input().split()))
def rl(): return list(map(int, input().split()))
def rs(): return input().rstrip()
def out_list(x): return ' '.join(map(str, x))

MOD = 10**9 + 7
INF = float('inf')

def solve_case():
    n, m = rl()
    A = rl()
    s = [(a, i) for i, a in enumerate(A)]
    s.sort(key=lambda x: (x[0], -x[1]))
    # print('===', s)
    res = 0
    seats = [INF] * m
    idx = 0
    for a, i in s:
        seats[idx] = i
        idx += 1
        res += sum(seats[j] < i for j in range(idx))
        # print('===', seats)
    print(res)

if __name__ == '__main__':
    # T = 1
    T = int(input())
    for test_case in range(1, T + 1):
        # print("Case #{}: ".format(test_case), end='')
        solve_case()
