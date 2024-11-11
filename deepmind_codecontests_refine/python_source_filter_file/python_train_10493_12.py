import math
a,b,x=map(int,input().split())
V=a**2*b
if x>=V/2:
    theta=math.atan((2*a**2*b-2*x)/a**3)
else:
    theta=math.atan((a*b*b)/2*x)
print(math.degrees(theta))