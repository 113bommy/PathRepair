import math
a,b,c = input().split()
a = int(a)
b = int(b)
c = int(c)
x = (-b + math.sqrt(b**2 - 4*a*c))/(2*a)
y = (-b - math.sqrt(b**2 - 4*a*c))/(2*a)
if x < y:
    print(y)
    print(x)
if y < x:
    print(x)
    print(y)