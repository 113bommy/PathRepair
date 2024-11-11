import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,copy,functools

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
    n,k = LI()
    l = []
    sq = int(n ** 0.5) + 1
    for i in range(1,sq+1):
        l.append((i,n//i,1))

    t = sq
    # print(sq,l)
    for j,i,_ in l[::-1]:
        # print(j,i,_)
        if t >= i:
            continue
        c = i - t
        l.append((i,j,c))
        t = i

    # print(l)

    ll = len(l)
    dp = [[0] * ll for _ in range(k+1)]
    dp[0][0] = 1

    l.append((inf,0,0))
    for i in range(k):
        dpi = dp[i]
        np = dp[i+1]
        m = 0
        c = 0
        for j in range(ll-1,-1,-1):
            t = l[j][1]
            tc = l[j][2]
            while l[m][0] <= t:
                c += dpi[m]
                c %= mod
                m += 1
            np[j] = c * tc % mod

    # print(dp)
    return sum(dp[-1]) % mod


print(main())

