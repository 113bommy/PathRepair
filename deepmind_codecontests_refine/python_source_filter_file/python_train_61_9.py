import math
import itertools
import collections

def getdict(n):
    d = {}
    if type(n) is list:
        for i in n:
            if i in d:
                d[i] += 1
            else:
                d[i] = 1
    else:
        for i in range(n):
            t = ii()
            if t in d:
                d[t] += 1
            else:
                d[t] = 1
    return d
def cdiv(n, k): return n // k + (n % k != 0)
def ii(): return int(input())
def mi(): return map(int, input().split())
def li(): return list(map(int, input().split()))
def lcm(a, b): return abs(a*b) // math.gcd(a, b)
def sumc(t):
    s = 0
    while t > 0:
        s += t % 10
        t //= 10
    return s

p = input()
n = ii()
p0, p1, w = [], [], []
for i in range(n):
    s = input()
    p0.append(s[0])
    p1.append(s[1])
    w.append(s)
if p[1] in p0 and p[0] in p1 or s in w:
    print('YES')
else:
    print('NO')
