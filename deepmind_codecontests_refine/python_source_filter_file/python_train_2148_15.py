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

n = ii()
a = li()
b = [0]*(2 * 10 ** 5 + 1)
for i in range(n):
    b[a[i]] = i + 1
ans = 2 * 10 ** 5
print(b)
for i in range(2 * 10 ** 5 + 1):
    if b[i] != 0:
        ans = min(ans, b[i] - 1)
print(a[ans])