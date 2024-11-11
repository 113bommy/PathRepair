# -*- coding: utf-8 -*-
"""
Created on Fri Mar  8 01:07:36 2019

@author: Owner
"""

def gcd(x, y):
    if x < y:
        return gcd(y, x)
    if y == 0:
        return x
    return gcd(y, x % y)

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
d = {}
for i, j in zip(a, b):
    if j == 0:
        if i == 0:
            d[0, 0] = d.get((0, 0), 0) + 1
        else:
            d[1, 0] = d.get((1, 0), 0) + 1
        continue
    if i == 0:
        continue
    g = gcd(abs(i), abs(j))
    x = i // g
    y = j // g
    if x < 0:
        x *= -1
        y *= -1
    d[x, y] = d.get((x, y), 0) + 1
ans = 0
for i in d.values():
    if i == (0, 0):
        continue
    ans = max(ans, i)
print(ans + d.get((0, 0), 0))