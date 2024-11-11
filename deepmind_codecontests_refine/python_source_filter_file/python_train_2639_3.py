__author__ = 'asmn'
from math import sqrt, atan2, pi, sin
from functools import reduce

x, y = [0] * 3, [0] * 3
for i in range(3):
    x[i], y[i] = tuple(map(float, input().split()))


def center(x, y, n):
    return (sum(x[i] * x[i] * (y[i - 1] - y[i - 2]) for i in range(3)) + (y[0] - y[1]) * (y[1] - y[2]) * (
    y[2] - y[0])) / sum(2 * x[i] * (y[i - 1] - y[i - 2]) for i in range(3))


cx, cy = center(x, y, 3), center(y, x, 3)

r = sqrt((x[1] - cx) ** 2 + (y[1] - cy) ** 2)

th = list(map(lambda x, y: atan2(y - cy, x - cx), x, y))


def check(na, a):
    k = na / a
    return abs(k - round(k)) < 1e-6


for n in range(3, 101):
    if check(th[2] - th[0], 2 * pi / n) and check(th[1] - th[0], 2 * pi / n):
        print(n * r * r * sin(2 * pi / n) / 2)
        break



