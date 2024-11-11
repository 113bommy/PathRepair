import math
a,b,x = map(int,input().split())
if 2*x<=a*a*b:
    y = math.degrees(math.atan( 2*b/a-2*x/a**3 ))
else:
    y = math.degrees(math.atan( a*b**2/(2*x) ))
print(y)