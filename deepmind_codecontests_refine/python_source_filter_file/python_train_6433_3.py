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
    n = I()
    print((n-(n>>1))/n)
    return

#B
def B():
    n,k = LI()
    h = LI()
    ans = 0
    for i in h:
        if i >= k:
            ans += 1
    print(ans)
    return

#C
def C():
    n = I()
    a = LI()
    b = [(a[i],i+1) for i in range(n)]
    b.sort()
    ans = [b[i][1] for i in range(n)]
    print(*ans)
    return

#D
def D():
    def divisor(n):
        if n < 4:
            return set([n])
        res = set([1])
        i = 2
        m = n
        while i**2 <= n:
            if m%i == 0:
                while m%i == 0:
                    m //= i
                res.add(i)
            i += 1
        res.add(m)
        return res
    a,b = LI()
    if min(a,b) == 1:
        print(1)
        return
    s = divisor(a)
    t = divisor(b)
    s &= t
    print(len(s))
    return

#E
def E():
    n,m = LI()
    v = []
    for i in range(m):
        a,b = LI()
        c = LI()
        s = 0
        for j in c:
            s |= 1<<(j-1)
        v.append((a,s))
    l = 1<<n
    dp = [[float("inf")]*l for i in range(m+1)]
    dp[0][0] = 0
    for i in range(m):
        ni = i+1
        a,c = v[i]
        for b in range(l):
            if dp[i][b] == float("inf"):
                continue
            nb = b|c
            nd = dp[i][b]+a
            if nd < dp[ni][nb]:
                dp[ni][nb] = nd
            nd = dp[i][b]
            if nd < dp[ni][b]:
                dp[ni][b] = nd
    if dp[m][-1] == float("inf"):
        print(-1)
    else:
        print(dp[m][-1])
    return

#F
def F():
    def dijkstra(s):
        dist = defaultdict(lambda : float("inf"))
        dist[(s,0)] = 0
        q = deque([(s,0)])
        pre = [None]*n
        while q:
            x,k = q.popleft()
            dx = d[(x,k)]
            if x == s and k:
                break
            nd = dx+1
            for y in v[x]:
                if y == s:
                    nk = 1
                else:
                    nk = 0
                if dist[(y,nk)] = float("inf"):
                    dist[(y,nk)] = nd
                    pre[y] = x
                    q.append((y,nk))
        return (dist,pre)

    n,m = LI()
    v = [[] for i in range(n)]
    for i in range(m):
        a,b = LI()
        a -= 1
        b -= 1
        v[a].append(b)

    di,p,s = float("inf"),[],None
    for x in range(n):
        dist,pre = dijkstra(x)
        if dist[(x,1)] < di:
            di = dist[(x,1)]
            p = pre
            s = x
    if di == float("inf"):
        print(-1)
        return
    ans = [s+1]
    x = p[s]
    while x != s:
        ans.append(x+1)
        x = p[x]
    ans.sort()
    print(len(ans))
    for i in ans:
        print(i)
    return

#Solve
if __name__ == "__main__":
    F()
