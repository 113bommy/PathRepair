R, x1, y1, x2, y2 = map(int, input().split())
r2 = (x1-x2)**2 + (y1-y2)**2
if  r2 >= R**2:
    print(y1, x1, R)
elif y1 == y2:
    r = (R + abs(x1 - x2)) / 2
    b = y1
    if(x1 < x2):
        a = x2 - r
    else:
        a = x2 + r
    print(a, b, r)
elif x1 == x2:
    r = (R + abs(y1 - y2)) / 2
    a = x1
    if(y1 < y2):
        b = y2 - r
    else:
        b = y2 + r
    print(a, b, r)
else:
    r = R + r2**(1/2)
    r/=2
    #print(r)
    r1 = r - r2**(1/2)
    tg = abs((y1 - y2) / (x1 - x2))
    a2 = r1**2 / (1 + tg**2)
    b2 = r1**2 - a2
    a2 = a2**(1/2)
    b2 = b2**(1/2)

    if x2 > x1:
        a2 = -a2
    if(y2 > y1):
        b2 = -b2

    a2 += x1
    b2 += y1
    print(a2, b2, r)

