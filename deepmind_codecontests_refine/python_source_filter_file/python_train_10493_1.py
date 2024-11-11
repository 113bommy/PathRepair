import math
a,b,x = map(int,input().split())
if a*a*b/2 >= x:
    print(math.degrees(math.atan(a*b*b/(2*x))))
else:
    print(90-math.degrees(math.atan(2*(b*a*a-x)/(a**3))))