#!/usr/bin/env python3
import sys
input = sys.stdin.readline
import math
eps = 1e-12

def calc_intersection_points(circle0, circle1):
    x0, y0, r0 = circle0
    x1, y1, r1 = circle1
    d = math.hypot(x0 - x1, y0 - y1)
    if d > r0 + r1 or d < abs(r0 - r1):
        return []
    ret = []
    if r0 + r1 == d:
        a = r0
        h = 0.0
    else:
        a = (r0**2 - r1**2 + d**2) / (2.0 * d)
        h = math.sqrt(r0**2 - a**2)
    x2 = x0 + a * (x1 - x0) / d
    y2 = y0 + a * (y1 - y0) / d
    x3 = x2 + h * (y1 - y0) / d
    y3 = y2 - h * (x1 - x0) / d
    ret.append((x3, y3))
    if h == 0:
        return ret
    x4 = x2 - h * (y1 - y0) / d
    y4 = y2 + h * (x1 - x0) / d
    ret.append((x4, y4))
    return ret


n, k = map(int, input().split())
niku = []
for _ in range(n):
    x, y, c = map(int, input().split())
    niku.append((x, y, c))

l = 0.0; r = 10**8
for _ in range(1000):
    mid = (l + r) / 2.0
    circles = []
    for x, y, c in niku:
        circles.append((x, y, mid / c))
    points = []
    for i in range(n):
        for j in range(i+1, n):
            points += calc_intersection_points(circles[i], circles[j])
    for x, y, _ in niku:
        points.append((x, y))
    cooked = 0
    for x, y in points:
        ret = 0
        for cx, cy, cr in circles:
            if math.hypot(x - cx, y - cy) <= cr + eps:
                ret += 1
        if ret > cooked:
            cooked = ret
    if cooked >= k:
        r = mid
    else:
        l = mid
print(l)