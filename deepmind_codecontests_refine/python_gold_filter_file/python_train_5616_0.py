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

    while True:
        n,m = LI()
        if n == 0 and m == 0:
            break
        a = [I() for _ in range(n)]
        b = [I() for _ in range(m)]
        ar = [0] * (n+1)
        for i in range(n):
            ar[i+1] = ar[i] + a[i]
        ad = collections.defaultdict(int)
        for i in range(n+1):
            for j in range(i+1,n+1):
                ad[ar[j]-ar[i]] += 1
        br = [0] * (m+1)
        for i in range(m):
            br[i+1] = br[i] + b[i]
        bd = collections.defaultdict(int)
        for i in range(m+1):
            for j in range(i+1,m+1):
                bd[br[j]-br[i]] += 1

        r = 0
        for k in ad.keys():
            r += ad[k] * bd[k]

        rr.append(r)



    return '\n'.join(map(str, rr))


print(main())


