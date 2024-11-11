import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,copy,functools
# import time,random,resource

# sys.setrecursionlimit(10**6)
inf = 10**20
eps = 1.0 / 10**10
mod = 10**9+7
mod2 = 998244353
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
def IF(c, t, f): return t if c else f
def YES(c): return IF(c, "YES", "NO")
def Yes(c): return IF(c, "Yes", "No")


def main():
    t = 1#I()

    rr = []
    for _ in range(t):
        s = S()

        l = len(s)
        li = -1
        for i in range(l):
            if s[i] == '[':
                li = i
                break

        if li < 0:
            rr.append(-1)
            continue

        for i in range(li+1,l):
            if s[i] == ':':
                li = i
                break

        if s[li] != ':':
            rr.append(-1)
            continue

        ri = l
        for i in range(l-1,-1,-1):
            if s[i] == ']':
                ri = i
                break

        if ri == l:
            rr.append(-1)
            continue

        for i in range(ri-1,-1,-1):
            if s[i] == ':':
                ri = i
                break

        if s[ri] != ':' or li >= ri:
            rr.append(-1)
            continue

        if li == ri:
            rr.append(l - 3)
        else:
            c = len([_ for _ in s[li+1:ri] if _ == '|'])
            rr.append(l - c - 4)

    return JA(rr, "\n")


print(main())


