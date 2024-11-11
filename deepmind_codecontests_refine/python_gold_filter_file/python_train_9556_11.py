import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,copy,functools
import time,random

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
def JA(a, sep): return sep.join(map(str, a))
def JAA(a, s, t): return s.join(t.join(map(str, b)) for b in a)


def main():
    n,x,d = LI()
    if d == 0:
        if x == 0:
            return 1
        return n + 1

    c = collections.defaultdict(list)
    ad = n * (n-1) // 2 * d + x * n
    # print(ad)
    dd = abs(d)*2
    for i in range(n+1):
        u = ad - (x * i + ((i-1) * i // 2) * d) * 2
        k = ad - (x * i + ((n-1 + n-i) * i // 2) * d) * 2
        # print("iku",i,k,u)
        if k > u:
            k,u = u,k
        c[k%dd].append((k,u))

    r = 0
    for k, v in c.items():
        v.sort()
        # print(k,v)
        a,b = v[0]
        for t,u in v[1:]:
            if t <= b:
                if b < u:
                    b = u
            else:
                r += (b-a) // dd + 1
                # print("ab",a,b,(abs(b-a)+dd), dd,r)
                a,b = t,u
        r += (b-a) // dd + 1

    return r


print(main())


