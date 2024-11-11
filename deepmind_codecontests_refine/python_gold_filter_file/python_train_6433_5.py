#!/usr/bin/env python3
from collections import defaultdict,deque
from heapq import heappush, heappop
from bisect import bisect_left, bisect_right
import sys, random, itertools, math
sys.setrecursionlimit(10**5)
input = sys.stdin.readline
sqrt = math.sqrt
def LI(): return list(map(int, input().split()))
def LF(): return list(map(float, input().split()))
def LI_(): return [int(i)-1 for i in input().split()]
def II(): return int(input())
def IF(): return float(input())
def LS(): return list(map(list, input().split()))
def S(): return list(input().rstrip())
def IR(n): return [II() for _ in range(n)]
def LIR(n): return [LI() for _ in range(n)]
def FR(n): return [IF() for _ in range(n)]
def LFR(n): return [LI() for _ in range(n)]
def LIR_(n): return [LI_() for _ in range(n)]
def SR(n): return [S() for _ in range(n)]
def LSR(n): return [LS() for _ in range(n)]
mod = 1000000007
inf = float('INF')

#A
def A():
    n = II()
    ans = 0
    for i in range(1, n + 1):
        ans += i & 1
    print(ans/n)
    return

#B
def B():
    _, k = LI()
    h = LI()
    ans = 0
    for i in h:
        ans += i >= k
    print(ans)
    return

#C
def C():
    n = II()
    a = LI()
    d = defaultdict(int)
    for i in range(n):
        d[a[i] + 1] = i + 1
    for _, v in sorted(d.items()):
        print(v, end=" ")
    print()
    return

def primes(n):
    """ Input n>=6, Returns a list of primes, 2 <= p < n """
    """ 6以上の数であれば p (素数) <= n のlistを返す """
    n, correction = n-n%6+6, 2-(n%6>1)
    sieve = [True] * (n//3)
    for i in range(1,int(n**0.5)//3+1):
        if sieve[i]:
            k=3*i+1|1
            sieve[      k*k//3      ::2*k] = [False] * ((n//6-k*k//6-1)//k+1)
            sieve[k*(k-2*(i&1)+4)//3::2*k] = [False] * ((n//6-k*(k-2*(i&1)+4)//6-1)//k+1)
    return [2,3] + [3*i+1|1 for i in range(1,n//3-correction) if sieve[i]]

#D
def D():
    a, b = LI()
    da = defaultdict(int)
    db = defaultdict(int)
    for i in range(2, int(math.sqrt(a)) + 1):
        while a % i == 0:
            a = a // i
            da[i] = 1
        while b % i == 0:
            b = b // i
            db[i] = 1
    da[a] = 1
    db[b] = 1
    da[1] = 1
    db[1] = 1
    print(len(set(da.keys()) & set(db.keys())))
    return

#E
def E():
    n, m = LI()
    dp = [inf] * (1 << n)
    dp[0] = 0
    for _ in range(m):
        a, b = LI()
        c = LI_()
        fulls = sum((1<<c[i] for i in range(b)))
        for i in range(1 << n):
            dp[i | fulls] = min(dp[i | fulls], dp[i] + a)
    if dp[-1] == inf:
        print(-1)
    else:
        print(dp[-1])
    return

#F
def F():
    n,m = LI()
    edg = [[] for i in range(n)]
    redg = [[] for i in range(n)]
    
    for _ in range(m):
        a, b = LI_()
        edg[a].append(b)
        redg[b].append(a)

    def dijkstra(start):
        dist = [inf] * n
        dist[start] = 0
        q = [(0,start)]
        while q:
            du, u = heappop(q)
            for i in edg[u]:
                if du + 1 < dist[i]:
                    dist[i] = du + 1
                    heappush(q, (du + 1, i))
        return dist
    
    d = [None] * n
    for i in range(n):
        d[i] = dijkstra(i)

    tmp = inf
    tt = None
    for i in range(n):
        for j in range(n):
            if i == j:
                continue
            if tmp > d[i][j] + d[j][i]:
                tt = (i, j)
                tmp = d[i][j] + d[j][i]

    if tmp != inf:
        print(tmp)
        s, g = tt
        ans1 = [s]
        ans2 = [g]
        q = deque([s])
        while q:
            a = q.pop()
            for ai in redg[a]:
                if g != ai and d[g][ai] + 1 == d[g][a]:
                    ans1.append(ai)
                    q.append(ai)
                    break
        q = deque([g])
        while q:
            a = q.pop()
            for ai in redg[a]:
                if s != ai and d[s][ai] + 1 == d[s][a]:
                    ans2.append(ai)
                    q.append(ai)
                    break
        ans = ans1 + ans2
        for a in ans:
            print(a+1)

    else:
        print(-1)
    return

#Solve
if __name__ == '__main__':
    F()
