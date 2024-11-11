import math
a,b,h,m = map(int,input().split())
x = a**2+b**2-2*a*b*math.cos(math.radians(int(30*h-6*m)))
print(x**(1/2))
