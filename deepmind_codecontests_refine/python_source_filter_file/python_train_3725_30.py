import math
a,b,h,m = map(int,input().split())
c2= a**2+b**2-2*a*b*math.cos(math.radians(30*h-6*m))
print(math.sqrt(c2))