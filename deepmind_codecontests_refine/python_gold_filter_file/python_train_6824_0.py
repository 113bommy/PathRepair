import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,copy,functools
import random

sys.setrecursionlimit(10**7)
inf = 10**20
eps = 1.0 / 10**10
mod = 10**9+7
dd = [(-1,0),(0,1),(1,0),(0,-1)]
ddn = [(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1),(0,-1),(-1,-1)]

def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(): return [list(map(int, l.split())) for l in sys.stdin.readlines()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
def pf(s): return print(s, flush=True)
def pe(s): return print(str(s), file=sys.stderr)


def main():
    n = I()
    a = LI()
    aa = [S() for _ in range(n)]
    dp = [0, 0]
    t = ''
    tr = ''
    for i in range(n):
        s = aa[i]
        np = [inf, inf]
        if t <= s:
            np[0] = dp[0]
        if tr <= s and np[0] > dp[1]:
            np[0] = dp[1]
        sr = s[::-1]
        if t <= sr:
            np[1] = dp[0] + a[i]
        if tr <= sr and np[1] > dp[1] + a[i]:
            np[1] = dp[1] + a[i]

        t = s
        tr = sr

        dp = np

    r = min(dp)
    if r >= inf:
        return -1

    return r


print(main())

