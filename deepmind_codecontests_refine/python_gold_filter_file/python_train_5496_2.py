# -*- coding: utf-8 -*-
M = int(input())
d = 0
c = 0
for _ in range(M):
    c1, d1 = map(int, input().split())
    d += d1
    c += c1 * d1

if c % 9 != 0:
    s = c // 9
else:
    s = c // 9 - 1

print((d - 1) + s)     