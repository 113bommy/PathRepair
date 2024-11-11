import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
eps = 1.0 / 10**10
mod = 998244353

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
def pf(s): return print(s, flush=True)


def main():
    rr = []

    def f(k):
        p,a,b,c,d,e,f,s,m = map(int,k[1:])
        t = a + b + c + (d + e) * (m - 1)
        u = f * s * m - p
        return (-u / t, k[0])

    while True:
        n = I()
        if n == 0:
            break

        a = [LS() for _ in range(n)]
        b = [f(c) for c in a]
        b.sort()
        for u,l in b:
            rr.append(l)
        rr.append('#')

    return '\n'.join(map(str, rr))


print(main())


