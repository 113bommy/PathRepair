import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
eps = 1.0 / 10**15
mod = 10**9+7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
def pf(s): return print(s, flush=True)


def main():
    n = I()
    if n == 3:
        return '2 5 63'
    if n == 4:
        return '2 5 20 63'
    a = []
    c = 1
    for i in range(n):
        while c%2 > 0 and c%3 > 0 and c%5 > 0:
            c += 1
        a.append(c)
        c += 1
    a[-3] += 30 - (a[-3] % 30)
    a[-2] += 60 - (a[-2] % 30)
    a[-1] += 90 - (a[-1] % 30)
    t = sum(a)
    while t % 2 == 1:
        a[-3] += 3
        t += 3
    while t % 3 > 0:
        a[-2] += 5
        t += 5
    while t % 5 > 0:
        a[-1] += 6
        t += 6

    return ' '.join(map(str, a))


print(main())


