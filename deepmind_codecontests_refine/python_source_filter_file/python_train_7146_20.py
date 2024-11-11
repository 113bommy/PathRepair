from math import hypot
r, x1, y1, x2, y2 = map(int, input().split())
if (x1 - x2) ** 2 + (y1 - y2) ** 2 >= r ** 2:
    print(x1, y1, r)
elif x1 == x2 and y1 == y2:
    print((x1 + r) / 2, y1, r / 2)
else:
    of = hypot(x2 - x1, y2 - y1)
    rn = (r + of) / 2
    xn = -r / of * (x2 - x1) + x1
    yn = -r / of * (y2 - y1) + y1
    x = (xn + x2) / 2
    y = (yn + y2) / 2
    print(x, y, rn)
