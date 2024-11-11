import math
a,b,h,m = map(int,input().split())
print(a**2+b**2-2*a*b*math.cos(math.radians(h*30 - m*5.5)))**0.5