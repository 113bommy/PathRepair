import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time

sys.setrecursionlimit(10**7)
inf = 10**20
mod = 10**9 + 7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()

def main():
    n,m = LI()
    e = collections.defaultdict(set)
    for _ in range(m):
        a,b = LI()
        e[a-1].add(b-1)
        e[b-1].add(a-1)
    r = [0] * n

    q = I()
    qq = sorted([[_] + LI() for _ in range(q)], reverse=True)
    f = [-1] * n
    for _,v,d,c in qq:
        v -= 1
        if f[v] >= d:
            continue
        if r[v] == 0:
            r[v] = c
        q = [v]
        for nd in range(d-1,-1,-1):
            t = []
            for p in q:
                for vv in e[p]:
                    if f[vv] >= nd:
                        continue
                    f[vv] = nd
                    t.append(vv)
                    if r[vv] == 0:
                        r[vv] = c
            q = t

    return '\n'.join(map(str, r))



print(main())
