import math
r, x1, y1, x2, y2 = list(map(int, input().split()))
d2 = (x1 - x2) ** 2 + (y1 - y2) ** 2
print(int(math.sqrt(d2) + 2 * r - 1e-3) // (2 * r))