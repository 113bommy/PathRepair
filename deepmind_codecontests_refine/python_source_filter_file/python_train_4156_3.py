import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
eps = 1.0 / 10**10
mod = 10**9+7
dd = [(0,-1),(1,0),(0,1),(-1,0)]
ddn = [(0,-1),(1,-1),(1,0),(1,1),(0,1),(-1,-1),(-1,0),(-1,1)]

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
        w,h = LI()
        if h == 0:
            break
        a = [LI() for _ in range(h)]
        s = t = None
        for i in range(h):
            for j in range(w):
                if a[i][j] == 2:
                    s = (i,j)
                    a[i][j] = 0
                elif a[i][j] == 3:
                    t = (i,j)
        q = set([(s,tuple())])
        tr = -1
        for i in range(1,11):
            nq = set()
            for c,l in q:
                l = list(l)
                for di,dj in dd:
                    ni = c[0]
                    nj = c[1]
                    while 0 <= ni < h and 0 <= nj < w and (a[ni][nj] == 0 or (ni,nj) in l):
                        ni += di
                        nj += dj
                    if (ni,nj) == t:
                        tr = i
                        break
                    if ni < 0 or ni >= h or nj < 0 or ni >= w:
                        continue
                    ni -= di
                    nj -= dj
                    if ni != c[0] or nj != c[1]:
                        nq.add(((ni,nj), tuple(sorted(l + [(ni+di,nj+dj)]))))
                if tr > 0:
                    break
            if tr > 0:
                break
            q = nq
        rr.append(tr)

    return '\n'.join(map(str, rr))



print(main())

