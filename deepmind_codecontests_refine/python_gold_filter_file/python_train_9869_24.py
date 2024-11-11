#!/usr/bin/env python3
from fractions import gcd
a, b = map(int, input().split())
g = gcd(a, b)
ans = {}
for i in range(2, int(g**0.5 + 1)):
    while g % i == 0:
        ans[i] = ans[i] + 1 if i in ans else 1
        g //= i
if g != 1:
    ans[g] = 1
print(len(ans) + 1)
