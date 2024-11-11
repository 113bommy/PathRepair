import math
for i in range(int(input())):
    xa, ya, ra, xb, yb, rb = list(map(float, input().split()))

    d1 = (xa - xb) ** 2 + (ya - yb) ** 2
    d2 = ra ** 2 + rb ** 2
    dr = (ra-rb) ** 2

    if d1 <= d2:
        if dr >= d1:
            print(2 if ra > rb else -2)
        else:
            print(1)
    else:
        print(0)