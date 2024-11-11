import math
import bisect
import heapq
from collections import defaultdict


def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, x, y = egcd(b % a, a)
        return (g, y - (b // a) * x, x)


def mulinv(b, n):
    g, x, _ = egcd(b, n)
    if g == 1:
        return x % n



def isprime(n):
    for d in range(2, int(math.sqrt(n))+1):
        if n % d == 0:
            return False
    return True


def argsort(ls):
    return sorted(range(len(ls)), key=ls.__getitem__)


def f(p=0):
    if p == 1:
        return map(int, input().split())
    elif p == 2:
        return list(map(int, input().split()))
    elif p == 3:
        return list(input())
    else:
        return int(input())

n, m = f(2)

a = sorted(f(2))
b = sorted(f(2))

mn = a[-1]
mx = b[0]

smb = sum(b)
sma = sum(a)

if mx<mn:
    print(-1)
else:
    if a[-1]!=b[0]:
        res = a[-1]+smb-b[0]+(sum(a)-a[-1])*m-a[0]+b[0]
    else:
        res = smb+(sum(a)-a[-1])*m

    print(res)