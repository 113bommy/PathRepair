#!usr/bin/env python3
from collections import defaultdict,deque
from heapq import heappush, heappop
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

#A
def A():
    s = S()
    t = S()
    ans = 0
    for i in range(len(s)):
        if s[i] == t[i]:
            ans += 1
    print(ans)
    return

#B
def B():
    a,b = LI()
    for i in range(10000):
        if 1+i*a-i >= b:
            print(i)
            return
    return

#C
def C():
    n = I()
    a = LI()
    ans = 0
    r = 1
    for l in range(n):
        if r == l:
            r += 1
        while r < n and a[r-1] >= a[r]:
            r += 1
        ans = max(ans, r-l-1)
    print(ans)
    return

#D
def D():
    n = I()
    print(n*(n-1)>>1)
    return

#E
def E():
    def dfs(x,p):
        if dp[x] != None:
            return dp[x]
        dp[x] = -1
        for y in v[x]:
            if p[y]:
                dp[x] = float("inf")
                break
            p[y] = 1
            dp[x] = max(dp[x], dfs(y,p)+1)
            p[y] = 0
        return dp[x]

    n = I()
    a = LIR(n)
    for i in range(n):
        for j in range(n-1):
            a[i][j] -= 1
    m = n*(n-1)
    v = [[] for i in range(m)]
    for i in range(n):
        p = n*min(i, a[i][0]) + max(i, a[i][0])
        for j in range(n-2):
            p_ = n*min(i, a[i][j+1]) + max(i, a[i][j+1])
            v[p_].append(p)
            p = p_
    dp = defaultdict(lambda : None)
    for i in range(m):
        if not v[i]:
            dp[i] = 1
    ans = 1
    p = [0]*m
    for x in range(m):
        p[x] = 1
        if ans < dfs(x,p):
            ans = dp[x]
        p[x] = 0
    if ans == float("inf"):
        print(-1)
    else:
        print(ans)
    return

#E_
def E_():
    n = I()
    a = LIR(n)
    for i in range(n):
        for j in range(n-1):
            a[i][j] -= 1
    m = n*(n-1)
    v = [[] for i in range(m)]
    f = [0]*m
    for i in range(n):
        p = n*min(i, a[i][0]) + max(i, a[i][0])
        for j in range(n-2):
            p_ = n*min(i, a[i][j+1]) + max(i, a[i][j+1])
            v[p].append(p_)
            f[p] += 1
            p = p_
    q = []
    for i in range(m):
        heappush(q,(f[i],i))
    if q[0][0]:
        print(-1)
        return
    d = [1 if not f[i] else -1 for i in range(m)]
    bfs = [1]*m
    while q:
        fx, x = heappop(q)
        if not bfs[x]:
            continue
        bfs[x] = 0
        for y in v[x]:
            d[y] = d[x]+1
            f[y] -= 1
            if not f[y]:
                heappush(q,(0,y))
    print(d)
    return
#F
def F():
    n = I()
    p = LIR(n)
    p.sort(key = lambda x : (x[0] < 0, x[1]/x[0] if x[0] != 0 else x[1]*1e9))
    for i in range(n):
        p.append(p[i])
    ans = 0
    for i in range(n):
        d = [0,0]
        for j in range(i,n+i):
            d[0] += p[j][0]
            d[1] += p[j][1]
            dist = d[0]**2+d[1]**2
            if ans < dist:
                ans = dist
    print(ans**0.5)
    return

#Solve
if __name__ == "__main__":
    F()
