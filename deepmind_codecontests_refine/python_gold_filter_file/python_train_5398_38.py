#!/usr/bin/env python3
n, k, *a = map(int, open(0).read().split())
ans = 10**18
for i in range(2 << n):
    h = 0
    c = 0
    b = 0
    for j in range(n):
        if a[j] > h:
            b += 1
            h = a[j]
        elif i >> j & 1:
            c += h - a[j] + 1
            h += 1
            b += 1
    if b >= k:
        ans = min(ans, c)
print(ans)
