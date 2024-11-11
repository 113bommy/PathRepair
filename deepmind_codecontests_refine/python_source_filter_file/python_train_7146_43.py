from decimal import Decimal
import math

R, x1, y1, x2, y2 = [Decimal(x) for x in input().split()]
dis = Decimal.from_float(math.hypot(x1-x2, y1-y2))
if dis >= R * R:
    print(x1, y1, R)
elif x1 == x2 and y1 == y2:
    print(x1+R/2, y1, R/2)
else:
    r = (R + dis) / 2
    x = x2 + r*(x1-x2)/dis
    y = y2 + r*(y1-y2)/dis
    print(x, y, r)