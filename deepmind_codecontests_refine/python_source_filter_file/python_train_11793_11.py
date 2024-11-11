from math import asin, pi, sin
n, R, r = map(int, input().split())
if r > R:
    print('NO')
elif n > 1 and (R - r) * sin(pi / n) + 0.0001 < r:
    print('NO')
else:
    print('YES')
