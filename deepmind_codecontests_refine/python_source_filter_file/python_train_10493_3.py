a,b,x=map(int,input().split())
import math
if x/a<=a*b/2:
  print(math.degrees(math.atan(a*(b**2)/(2*x))))
else:
  print(math.degrees(math.atan((2*x)/(a**3))))