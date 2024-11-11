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

class BIT():
    def __init__(self, n):
        i = 1
        while 2**i <= n:
            i += 1
        self.H = i
        self.N = 2**i
        self.A = [0] * self.N

    def find(self, i):
        r = 0
        while i:
            r += self.A[i]
            i -= i & (i-1) ^ i
        return r

    def update(self, i, x):
        while i < self.N:
            self.A[i] += x
            i += i & (i-1) ^ i

    def query(self, a, b):
        return self.find(b-1) - self.find(a-1)

def main():
    n,m = LI()
    d = collections.defaultdict(list)
    for _ in range(n):
        l,r = LI()
        d[r-l+1].append((l,r))
    r = [n]
    bit = BIT(n+3)
    c = n
    for i in range(2,m+1):
        for a,b in d[i-1]:
            c -= 1
            bit.update(a,1)
            bit.update(b+1,-1)
        t = c
        for j in range(i,m+1,i):
            t += bit.find(j)
        r.append(t)

    return '\n'.join(map(str,r))


print(main())


