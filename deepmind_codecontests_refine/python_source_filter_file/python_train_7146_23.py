R, x1, y1, x2, y2 = map(int, input().split())
import math
if (x2-x1)**2+(y2-y1)**2 >= R**2:
    print(x1, y1, R)
else:
    if x1 == x2:
        if y2 <= y1:
            x = x1
            y = (y2+y1+R)/2
            r = y-y2
        else:
            x = x1
            y = (y2+y1-R)/2
            r = y2-y
    else:
        a = (y1-y2)/(x1-x2)
        d = R/math.sqrt(1+a**2)
        if x2 <= x1:
            xd = x1+d
            yd = a*(xd-x1)+y1
            x = (x2+xd)/2
            y = (y2+yd)/2
            r = math.hypot(xd-x, yd-y)
        else:
            xd = x1-d
            yd = a*(xd-x1)+y1
            x = (x2+xd)/2
            y = (y2+yd)/2
            r = math.hypot(xd-x, yd-y)
        print(x, y, r)
