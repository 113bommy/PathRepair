from sys import stdin
import sys
import math
from functools import reduce
import functools
import itertools
from collections import deque,Counter,defaultdict
from operator import mul
import copy
# ! /usr/bin/env python
# -*- coding: utf-8 -*-
import heapq
sys.setrecursionlimit(10**6)
INF =  float("inf")
import bisect
import statistics
mod = 10**9+7

def popcount(x):
    '''xの立っているビット数をカウントする関数
    (xは64bit整数)'''

    # 2bitごとの組に分け、立っているビット数を2bitで表現する
    x = x - ((x >> 1) & 0x5555555555555555)

    # 4bit整数に 上位2bit + 下位2bit を計算した値を入れる
    x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333)

    x = (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0f # 8bitごと
    x = x + (x >> 8) # 16bitごと
    x = x + (x >> 16) # 32bitごと
    x = x + (x >> 32) # 64bitごと = 全部の合計
    return x & 0x0000007f

def bit(S, j):
    # Sの右からj bit目(0-indexed)
    return (S>>j)&1

N = int(input())
a = [[] for i in range(N)]
for i in range(N):
    a[i] = list(map(int, input().split()))

dp = [0 for i in range(1<<N)]
dp[0] = 1

for S in range(1,1<<N):
    i = popcount(S)
    for j in range(N):
        if bit(S,j) == 1 and a[i-1][j] == 1:
            dp[S] = (dp[S] + dp[S^(1<<j)]) % mod

print(dp[(1<<N)-1] % mod)