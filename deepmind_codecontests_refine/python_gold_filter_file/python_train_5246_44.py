import sys
import itertools
import math
import collections
from collections import Counter

#input = sys.stdin.readline

#########################
# imgur.com/Pkt7iIf.png #
#########################

def sieve(n):
    prime = [True for i in range(n + 1)]
    p = 2
    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p * 2, n + 1, p):
                prime[i] = False
        p += 1
    prime[0] = prime[1] = False
    r = [p for p in range(n + 1) if prime[p]]
    return r
def divs(n, start=1):
    r = []
    for i in range(start, int(math.sqrt(n) + 1)):
        if (n % i == 0):
            if (n / i == i):
                r.append(i)
            else:
                r.extend([i, n // i])
    return r
def flin(d, x, default = -1):
    f = l = -1
    for i in range(len(d)):
        if d[i] == x:
            if f == -1: f = i
            l = i
    if f == -1:
        return (default, default)
    else:
        return (f, l)
def ceil(n, k): return n // k + (n % k != 0)
def ii(): return int(input())
def mi(): return map(int, input().split())
def li(): return list(map(int, input().split()))
def lcm(a, b): return abs(a * b) // math.gcd(a, b)
def prr(a, sep=' '): print(sep.join(map(str, a)))
def dd(): return collections.defaultdict(int)


n = ii()
s = input()

fr, lr = flin(s, 'R')
fl, ll = flin(s, 'L')

if fr != -1 and fl != - 1:
    print(fr + 1, fl)
elif fr == -1:
    print(ll + 1, fl)
else:
    print(fr + 1, lr + 2)
