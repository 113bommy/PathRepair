from math import sqrt
r, x, y, x1, y1 = (int(x) for x in input().split())
dx = x - x1
dy = y - y1
n = sqrt(dx * dx + dy * dy) / r / 2.
print(int(n - 1e-7 + 1))
