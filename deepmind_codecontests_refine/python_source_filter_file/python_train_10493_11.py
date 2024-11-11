import math
a,b,x=map(int,input().split())
if x>=a*b/2:
    print(math.degrees(math.atan((b-x/(a**2))*2/a)))
else:
    print(math.degrees(math.atan(a*b**2/(2*x))))