import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time

sys.setrecursionlimit(10**7)
inf = 10**20
mod = 10**9 + 7

def LI(): return list(map(int, input().split()))
def II(): return int(input())
def LS(): return input().split()
def S(): return input()


def main():
    n = II()
    a = [0] + [II() for _ in range(n-1)]
    d = collections.defaultdict(list)
    for i in range(1,n):
        d[a[i]].append(i+1)
    m = {}
    def f(i):
        if not d[i]:
            return 0
        t = collections.defaultdict(int)
        for c in d[i]:
            t[f(c)] += 1
        t = list(t.items())
        t.sort()
        r = 0
        for c, tc in t:
            if r < c:
                r = c
            r += tc
        return r
    return f(1)


print(main())
