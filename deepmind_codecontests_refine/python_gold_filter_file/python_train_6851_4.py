#!usr/bin/env python3
from collections import defaultdict,deque
from heapq import heappush, heappop
from itertools import permutations
import sys
import math
import bisect
def LI(): return [int(x) for x in sys.stdin.readline().split()]
def I(): return int(sys.stdin.readline())
def LS():return [list(x) for x in sys.stdin.readline().split()]
def S():
    res = list(sys.stdin.readline())
    if res[-1] == "\n":
        return res[:-1]
    return res
def IR(n):
    return [I() for i in range(n)]
def LIR(n):
    return [LI() for i in range(n)]
def SR(n):
    return [S() for i in range(n)]
def LSR(n):
    return [LS() for i in range(n)]

sys.setrecursionlimit(1000000)
mod = 1000000007

"""
状態をそのままdpのインデックスとする。
https://drken1215.hatenablog.com/entry/2019/02/10/014800
"""

def solve():
    def cost(k,i):
        ai = a[i]
        if k == 0:
            return ai
        elif k == 1:
            if ai == 0:
                return 2
            return ai&1
        elif k == 2:
            return 1-(ai&1)
        elif k == 3:
            if ai == 0:
                return 2
            return ai&1
        else:
            return ai

    l = I()
    a = IR(l)
    dp = [[float("inf")]*5 for i in range(l)]
    for i in range(5):
        dp[0][i] = cost(i,0)
    for i in range(l-1):
        ni = i+1
        for j in range(5):
            for k in range(j,5):
                c = cost(k,ni)
                nd = dp[i][j]+c
                if nd < dp[ni][k]:
                    dp[ni][k] = nd
    print(min(dp[l-1]))
    return

#Solve
if __name__ == "__main__":
    solve()
