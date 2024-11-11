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
# 5
# 1 2 3 4 5
# 4
# 8 2 5 10
# 2
# 1000 2000
# 8
# 465 55 3 54 234 12 45 78

# """
# sys.stdin = io.StringIO(_INPUT)

INF = 10**10

class SegTree_GCD:
    def __init__(self, a):
        n = len(a)
        self.n1 = 2 ** (n-1).bit_length()
        self.dat = [0] * self.n1 + a + [-1] * (self.n1-n)
        for i in reversed(range(1, self.n1)):
            self.dat[i] = self.gcd1(self.dat[i*2], self.dat[i*2+1])
    
    def gcd1(self, v1, v2) -> int:
        if v1 == -1:
            return v2
        elif v2 == -1:
            return v1
        else:
            return math.gcd(v1, v2)

    def get_rgcd(self, l, r) -> int:
        l += self.n1
        r += self.n1
        v = -1
        while l < r:
            if l & 1:
                v = self.gcd1(v, self.dat[l])
                l += 1
            if r & 1:
                v = self.gcd1(v, self.dat[r-1])
                r -= 1
            l //= 2
            r //= 2
        return v

    def update(self, i, x) -> None:
        i += self.n1
        self.dat[i] = x
        while i > 1:
            i //= 2
            self.dat[i] = self.gcd1(self.dat[i*2], self.dat[i*2+1])

    def get_value(self, i) -> int:
        return self.dat[i+self.n1]

def solve(N, A):
    if N == 1:
        return 1
    elif N == 2:
        if abs(A[0]-A[1]) > 1:
            return 2
        else:
            return 1

    B = [abs(A[i+1] - A[i]) for i in range(N-1)]
    
    segt_gcd = SegTree_GCD(B)
    length = 0
    r = 1
    for l in range(N-1):
        r = l + length
        while r+1 <= N-1 and segt_gcd.get_rgcd(l, r+1) > 1:
            r += 1
        
        length = max(length, r-l)

    return length + 1

T0 = int(input())
for _ in range(T0):
    N = int(input())
    A = list(map(int, input().split()))
    print(solve(N, A))