from bisect import *
from math import *

n = int(input())
a, b, c, d = map(int,input().replace('/',' ').split())

alpha = atan2(c,d) - atan2(a,b)
tan_alpha = tan(alpha)

lis = []

for x,y in sorted((y/tan_alpha - x,y) for x,y in [ (x,y) for x,y in [(b*x + a*y,-a*x + b*y) for x, y in [map(int,input().split()) for _ in range(n)] if a*x - b*y <= 0 and d*y - c*x <= 0]]):
    pos = bisect_left(lis,-y)
    if pos == len(lis):
        lis.append(-y)
    else:
        lis[pos] = -y

print(len(lis))

