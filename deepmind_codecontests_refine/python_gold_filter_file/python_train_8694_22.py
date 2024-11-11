import math
a,b,c = map(int,input().split())
d = b**2 - 4*a*c
x1 = (-b + math.sqrt(d))/(2*a)
x2 = (-b - math.sqrt(d))/(2*a)
print(max(x1,x2))
print(min(x1,x2))