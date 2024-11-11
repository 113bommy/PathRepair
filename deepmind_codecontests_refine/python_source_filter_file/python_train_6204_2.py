#!/usr/bin/env python3
from sys import stdin,stdout
from decimal import *
def ri():
    return map(int, stdin.readline().split())
#lines = stdin.readlines()


def findt(rx,ry,vx,vy):
    if vx == 0:
        if rx > x1 and  rx < x2:
            t1x = Decimal(0)
            t2x = Decimal(10**6)
        else:
            return 2, 1
    else:
        t1x = Decimal(x1-rx)/Decimal(vx)
        t2x = Decimal(x2-rx)/Decimal(vx)

    if vy == 0:
        if ry > y1 and  ry < y2:
            t1y = Decimal(0)
            t2y = Decimal(10**6)
        else:
            return 2, 1
    else:
        t1y = Decimal(y1-ry)/Decimal(vy)
        t2y = Decimal(y2-ry)/Decimal(vy)

    if t1x > t2x:
        t1x, t2x = t2x, t1x
    if t1y > t2y:
        t1y, t2y = t2y, t1y

    return max(t1x, t1y), min(t2x, t2y)

n = int(input())
x1, y1, x2, y2 = ri()

if x1 > x2:
    x1, x2 = x2, x1
if y1 > y2:
    y1, y2 = y2, y1

mintt = 0
maxtt = 10**20
for i in range(n):
    rx, ry, vx, vy = ri()
    mint, maxt = findt(rx, ry, vx, vy)
    if mint > maxt:
        print(-1)
        exit()
    if maxt < 0:
        print(-1)
        exit()
    mintt = max(mint, mintt)
    maxtt = min(maxt, maxtt)
    if mintt > maxtt:
        print(-1)
        exit()
print(mintt)

