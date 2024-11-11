import math
from decimal import Decimal

px,py,vx,vy,a,b,c,d = map(Decimal, input().split())

h = (vx**2 + vy**2).sqrt()

vx, vy = vx / h, vy / h 

print("%0.60f %0.60f" % (px + vx * b, py + vy * b))
print("%0.60f %0.60f" % (px - a/2 * vy, py + a/2 * vx))
print("%0.60f %0.60f" % (px - c / 2 * vy, px + c / 2 * vx))
#print("%0.60f %0.60f" % (px + vx * b, py + vy * b))
#print("%0.60f %0.60f" % (px + vx * b, py + vy * b))

print("%0.60f %0.60f" % (px - c / 2 * vy - d * vx, px + c / 2 * vx - d*vy))
print("%0.60f %0.60f" % (px + c / 2 * vy - d * vx, px - c / 2 * vx - d*vy))

print("%0.60f %0.60f" % (px + c / 2 * vy, px - c / 2 * vx))
print("%0.60f %0.60f" % (px + a/2 * vy, py - a/2 * vx))