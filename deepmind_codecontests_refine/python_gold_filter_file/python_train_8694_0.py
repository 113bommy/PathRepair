import math
v=str(input())
v=v.split(' ')
a, b, c=int(v[0]), int(v[1]), int(v[2])
x1=(-b+math.sqrt(b**2-4*a*c))/(2*a)
x2=(-b-math.sqrt(b**2-4*a*c))/(2*a)
if x1>x2:
    print(x1, x2)
else: print(x2, x1)  