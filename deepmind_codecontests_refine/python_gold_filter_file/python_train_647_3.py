# aadiupadhyay
import os.path
from math import gcd, floor, ceil
from collections import *
import sys
mod = 1000000007
INF = float('inf')
def st(): return list(sys.stdin.readline().strip())
def li(): return list(map(int, sys.stdin.readline().split()))
def mp(): return map(int, sys.stdin.readline().split())
def inp(): return int(sys.stdin.readline())
def pr(n): return sys.stdout.write(str(n)+"\n")
def prl(n): return sys.stdout.write(str(n)+" ")


if os.path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')


def solve():
    n = inp()
    l = li()
    ans = 0
    cur = [-INF]*n
    for maxi in range(-30, 31):
        dp = list(cur)
        val = -INF
        if l[0] <= maxi:
            dp[0] = l[0]
        for i in range(1, n):
            if l[i] <= maxi:
                dp[i] = max(l[i], l[i]+dp[i-1])
            val = max(val, dp[i])
        ans = max(ans, val-maxi)
    pr(ans)


for _ in range(1):
    solve()
