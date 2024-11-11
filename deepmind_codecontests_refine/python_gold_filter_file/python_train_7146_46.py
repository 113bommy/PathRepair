from math import sqrt
R, x1, y1, x2, y2 = map(int, input().split())
s = sqrt((x2-x1)**2 + (y2-y1)**2)
r = (R + s) / 2
if s > R: print(x1, y1, R)
elif s:
    k = r/s
    print(x2 + (x1-x2)*k, y2 + (y1-y2)*k, r)
else: print(x2 + r, y2, r)