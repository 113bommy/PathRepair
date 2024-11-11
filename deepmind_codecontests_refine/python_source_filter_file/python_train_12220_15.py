#!/usr/bin/python3

from math import sin, cos, pi, atan2

x, y = tuple(map(int, input().split()))
if (x, y) in ((0, 0), (1, 0)):
    print(0)
elif x > 1 and -x + 1 < y <= x:
    print(1 + 4 * (x - 1))
elif x < 0 and x <= y < -x:
    print(3 + 4 * (-x - 1))
elif y > 0 and -y <= x < y:
    print(2 + 4 * (y - 1))
else:
    print(-4 * y)
