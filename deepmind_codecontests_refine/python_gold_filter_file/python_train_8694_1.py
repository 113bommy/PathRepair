import math
z=(input().split())
a=int(z[0])
b=int(z[1])
c=int(z[2])
d=b**2-4*a*c
x1=(-b-math.sqrt(d))/(2*a)
x2=(-b+math.sqrt(d))/(2*a)
print(max(x1,x2))
print(min(x1,x2))