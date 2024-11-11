import math 

(R, x1, y1, x2, y2) = map(int, input().split())

def xxx(x1, x2):
    global l, l0
    if x1 > x2:
        return l * (x1 - x2) / l0 + x2
    elif x1 < x2:
        return x2 - l * (x2 - x1) / l0
    return float(y1)

def yyy(x1, x2):
    global l, l0
    if y1 > y2:
        return l * (y1 - y2) / l0 + y2
    elif y1 < y2:
        return y2 - l * (y2 - y1) / l0
    return float(y1)

if (x2 - x1) ** 2 + (y2 - y1) ** 2 > R ** 2:
    print(x1, y1, R)
elif x1 == x2 and y1 == y2:
    print(x1 + R / 2, y1, R / 2)
else:
    l = (math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2) + R) / 2
    l0 = math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)    
    print(xxx(x1, x2), yyy(y1, y2), l)
