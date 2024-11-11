from math import sqrt

r, x1, y1, x2, y2 = map(int,input().split())
l = sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)
if l > r:
    print(x1, y1, r)
elif l:
    new_r = (r + l) / 2
    k = new_r / l - 1
    print(x1 + (x1 - x2) * k, y1 + (y1 - y2) * k, new_r)
else:
    new_r = r / 2
    print(x1 + new_r, y1, new_r)