#!usr/bin/env python3
from collections import defaultdict, deque
from heapq import heappush, heappop
from itertools import permutations, accumulate
import sys
import math
import bisect
def LI(): return [int(x) for x in sys.stdin.buffer.readline().split()]
def I(): return int(sys.stdin.buffer.readline())
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
    x = LI()
    f = [[] for i in range(n)]
    l = I()
    for i in range(n):
        xi = x[i]
        j = bisect.bisect_right(x,l+xi)-1
        f[i].append(j)
    h = int(math.log(n,2))+1
    for j in range(h-1):
        for i in range(n):
            f[i].append(f[f[i][j]][j])
    q = I()
    for _ in range(q):
        a,b = LI()
        a -= 1
        b -= 1
        if b < a:
            a,b = b,a
        ans = 0
        for i in range(h)[::-1]:
            if f[a][i] <= b:
                a = f[a][i]
                ans += 1<<i
        print(ans)
    return

#Solve
if __name__ == "__main__":
    solve()
