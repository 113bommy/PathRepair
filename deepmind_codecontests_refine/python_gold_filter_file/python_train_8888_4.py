import math
import itertools
import collections

def getdict(n):
    d = {}
    if type(n) is list or type(n) is str:
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
def wr(arr): return ' '.join(map(str, arr))
def revn(n): return int(str(n)[::-1])
def prime(n):
    if n == 2:
        return True
    if n % 2 == 0 or n <= 1:
        return False
    sqr = int(math.sqrt(n)) + 1
    for d in range(3, sqr, 2):
        if n % d == 0:
            return False
    return True

n = ii()
a, b = [], []
for i in range(n):
    ta, tb = mi()
    a.append(ta)
    b.append(tb)
ans = 0
for i in range(n):
    if a[i] not in b or b.count(a[i]) == 1 and b[i] == a[i]:
        ans += 1
print(ans)
