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


class Prime():
    def __init__(self, n):
        self.M = m = int(math.sqrt(n)) + 10
        self.A = a = [True] * m
        a[0] = a[1] = False
        self.T = t = []
        for i in range(2, m):
            if not a[i]:
                continue
            if not (i % 7 == 1 or i % 7 == 6):
                continue
            t.append(i)
            for j in range(i*i,m,i):
                a[j] = False

    def is_prime(self, n):
        return self.A[n]

    def division(self, n):
        d = []
        for c in self.T:
            if n < c:
                break
            if n % c == 0:
                d.append(c)
        return d

def main():
    rr = []

    pr = Prime(300000**2)

    while True:
        n = I()
        if n == 1:
            break

        d = pr.division(n)
        rr.append('{}:{}'.format(n,' '.join(map(str,d))))

    return '\n'.join(map(str, rr))


print(main())


