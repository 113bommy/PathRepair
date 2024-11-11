#!/usr/bin/env python3
from collections import defaultdict,deque
from heapq import heappush, heappop
from bisect import bisect_left, bisect_right
import sys, itertools, math, time
sys.setrecursionlimit(10**5)
input = sys.stdin.readline
sqrt = math.sqrt
def LI(): return list(map(int, input().split()))
def LF(): return list(map(float, input().split()))
def LI_(): return list(map(lambda x: int(x)-1, input().split()))
def II(): return int(input())
def IF(): return float(input())
def S(): return input().rstrip()
def LS(): return S().split()
def IR(n):
    res = [None] * n
    for i in range(n):
        res[i] = II()
    return res
def LIR(n):
    res = [None] * n
    for i in range(n):
        res[i] = LI()
    return res
def FR(n):
    res = [None] * n
    for i in range(n):
        res[i] = IF()
    return res
def LIF(n):
    res = [None] * n
    for i in range(n):
        res[i] = IF()
    return res
def SR(n):
    res = [None] * n
    for i in range(n):
        res[i] = S()
    return res
def LSR(n):
    res = [None] * n
    for i in range(n):
        res[i] = LS()
    return res
mod = 1000000007
inf = float('INF')
#solve
def solve():
    n = II()
    s = [None] * n
    dp = [None] * n
    for i in range(n):
        dp[i] = [-1] * 26
        s[i] = [input().rstrip(), i]
    for i in range(n):
        si,_ = s[i]
        dpi = dp[i]
        for j in range(len(si)):
            x = ord(si[j]) - ord("a")
            dpi[x] = j
    d = [s]
    ans = 0
    for i in range(10 ** 6):
        nd = []
        if not d: break
        for lis in d:
            tmp = [[] for i in range(26)]
            for l, k in lis:
                p = ord(l[i]) - ord("a")
                if len(l) == i + 1:
                    for x, m in lis:
                        if k != m:
                            if dp[m][p] >= i:
                                ans += 1
                else:
                    tmp[p].append((l, k))
            for k in tmp:
                if k:
                    nd.append(k)
        d = nd
    print(ans)
    return
#main
if __name__ == '__main__':
    solve()