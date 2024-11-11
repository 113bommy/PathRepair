#!usr/bin/env python3
from collections import defaultdict,deque
from heapq import heappush, heappop
from itertools import permutations
import sys
import math
import bisect
import random
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

def solve():
    n = I()
    a = LI()
    s = [1]*(n+1)
    for i in a:
        s[i] = 0
    odd = 0
    even = 0
    for i in range(1,n+1,2):
        odd += s[i]
    for i in range(2,n+1,2):
        even += s[i]
    dp = [[[[float("inf")]*2 for k in range(even+1)] for i in range(odd+1)] for j in range(n)]
    if a[0] != 0:
        dp[0][0][0][a[0]&1] = 0
    else:
        if odd:
            dp[0][1][0][1] = 0
        if even:
            dp[0][0][1][0] = 0
    for i in range(n-1):
        ni = i+1
        for j in range(odd+1):
            for k in range(even+1):
                if a[ni] != 0:
                    for l in range(2):
                        nl = a[ni]&1
                        nd = dp[i][j][k][l]+(l^nl)
                        if dp[ni][j][k][nl] > nd:
                            dp[ni][j][k][nl] = nd
                else:
                    nj = j+1
                    nk = k
                    nl = 1
                    if nj <= odd:
                        for l in range(2):
                            nd = dp[i][j][k][l]+(l^nl)
                            if dp[ni][nj][nk][nl] > nd:
                                dp[ni][nj][nk][nl] = nd
                    nj = j
                    nk = k+1
                    nl = 0
                    if nk <= even:
                        for l in range(2):
                            nd = dp[i][j][k][l]+(l^nl)
                            if dp[ni][nj][nk][nl] > nd:
                                dp[ni][nj][nk][nl] = nd
    print(min(dp[-1][odd][even]))
    return

#Solve
if __name__ == "__main__":
    solve()
