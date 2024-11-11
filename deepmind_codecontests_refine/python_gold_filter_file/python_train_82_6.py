import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
eps = 1.0 / 10**10
mod = 10**9+7
dd = [(-1,0),(0,1),(1,0),(0,-1)]
ddn = [(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1),(0,-1),(-1,-1)]

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
def pf(s): return print(s, flush=True)


def main():
    t = I()
    aa = [LI() for _ in range(t)]
    rr = []
    for a,b,c,d in aa:
        if a < b or d < b:
            rr.append('No')
            continue
        if c >= b:
            rr.append('Yes')
            continue
        g = fractions.gcd(b, d)
        if g == 1:
            if b - c > 1:
                rr.append('No')
            else:
                rr.append('Yes')
            continue
        t = (a + d - c) % g
        if t == 0:
            t = g
        if b - c - t > 0:
            rr.append('No')
        else:
            rr.append('Yes')

    return '\n'.join(rr)




print(main())
