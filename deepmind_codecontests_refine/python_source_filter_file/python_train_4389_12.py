import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,copy,functools

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
    n = I()
    s = [ord(c)-ord('a') for c in S()]
    t = [ord(c)-ord('a') for c in S()]
    r = [s[i]+t[i] for i in range(n)]
    for i in range(n-1,0,-1):
        if r[i] > 26:
            r[i] -= 26
            r[i-1] += 1
    k = 0
    rs = []
    for i in range(n):
        b = r[i] + k
        rs.append(chr(b // 2 + ord('a')))
        if b % 2 == 0:
            k = 0
        else:
            k = 26

    return ''.join(rs)


print(main())


