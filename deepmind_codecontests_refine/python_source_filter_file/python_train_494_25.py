import math
mod = 10**9 + 7
n = int(input())
d = {}
d0 = 0
for _ in range(n):
    a, b = map(int, input().split())
    g = math.gcd(a, b)
    if g == 0:
        d0 += 1
    else:
        a //= g
        b //= g
        if a < 0:
            a = -a
            b = -b
        elif a == 0 and b < 0:
            b = -b
        if (a,b) in d:
            d[(a,b)] += 1
        else:
            d[(a,b)] = 1
ans = 1
for (a,b) in d.keys():
    if d[(a,b)] > 0:
        t = 2**d[(a,b)]
        if b < 0:
            a = -a
            b = -b
        if (b,-a) in d:
            t += 2**d[(b,-a)] - 1
            d[(b,-a)] = 0
        ans *= t
        ans %= mod
print(ans+d0-1)