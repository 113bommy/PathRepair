from math import sqrt

def input_split(f): return map(f , input().split())

def timeCalc(x0, x1, y1, v0, v1):
    d = sqrt((x1 - x0) ** 2 + y1 ** 2)
    t0 = x0 / v0
    t1 = d / v1
    return (t1 + t0)


def Main():
    n, vb, vs = input_split(int)
    xn = []
    for i in input_split(int):
        xn.append(i)
    xu, yu = input_split(int)
    mn = 1e8
    pos = 0
    for i, dist in enumerate(xn):
        ti = timeCalc(dist, xu, yu, vb, vs)
        if(ti < mn):
            mn, pos = ti, i
    if (pos != 0):
        print (pos + 1)
    else:
        print (2)


Main()
