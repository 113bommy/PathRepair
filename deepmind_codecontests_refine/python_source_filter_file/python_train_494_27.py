from collections import defaultdict
from math import gcd

N = int(input())
X = [list(map(int, input().split())) for _ in range(N)]

d = {}
for a, b in X:
    if a == b == 0:
        pass
    elif a == 0:
        if b > 0:
            b = 1
        else:
            b = -1
    elif b == 0:
        if a > 0:
            a = 1
        else:
            a = -1
    else:
        v = gcd(a, b)
        a //= v
        b //= v

    if a > 0 and a * b >= 0:
        pair = (abs(a), abs(b))
        if pair not in d:
            d[pair] = [0, 0]
        d[pair][0] += 1
    else:
        pair = (abs(b), abs(a))
        if pair not in d:
            d[pair] = [0, 0]
        d[pair][1] += 1

mod = 10 ** 9 + 7
zero = 0
ans = 1
for p in d:
    if p == (0, 0):
        zero = d[p][1]
    else:
        a, b = d[p]
        ans *= pow(2, a, mod) + pow(2, b, mod) - 1
        ans %= mod
        
print((ans + zero - 1) % mod)
