#!/usr/bin/env python3

n, m = map(int, input().split())
minx = miny = n + m
maxx = maxy = - minx
dist = n + m + 1

c = int(input())
for _ in range(c):
    x, y = map(int, input().split())
    minx = min(minx, x - y)
    miny = min(miny, x + y)
    maxx = max(maxx, x - y)
    maxy = max(maxy, x + y)

h = int(input())
for i in range(h):
    a, b = map(int, input().split())
    x = a - b
    y = a + b
    maxxy = max(
        max(abs(minx - x), abs(maxx - x)),
        max(abs(miny - y), abs(maxy - y))
        )
    if  maxxy < dist:
        dist = maxxy
        res = i

print(dist)
print(res)
