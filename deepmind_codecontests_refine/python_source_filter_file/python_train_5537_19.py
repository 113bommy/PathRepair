import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,copy,functools
# import time,random,resource

# sys.setrecursionlimit(10**6)
inf = 10**20
eps = 1.0 / 10**10
mod = 10**9+7
mod2 = 998244353
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
def JA(a, sep): return sep.join(map(str, a))
def JAA(a, s, t): return s.join(t.join(map(str, b)) for b in a)
def IF(c, t, f): return t if c else f
def YES(c): return IF(c, "YES", "NO")
def Yes(c): return IF(c, "Yes", "No")


def main():
    t = 1

    rr = []
    for _ in range(t):
        a1 = I()
        a2 = I()
        k1 = I()
        k2 = I()
        n = I()

        if k1 > k2:
            a1,a2 = a2,a1
            k1,k2 = k2,k1

        t = max(0, n - ((k1-1) * a1 + (k2-1) * a2))
        u = min(a1, n//k1)
        n -= k1 * a1
        u += min(a2, n//k2)

        rr.append(JA([t,u], " "))

    return JA(rr, "\n")


print(main())


