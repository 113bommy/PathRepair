a,b,x=map(int,input().split())
import math
if a**2*b>=2*x:
  print(math.degrees(math.atan(2*(a**2*b-x)/(a**3))))
else:
  print(math.degrees(math.atan(b**2*a/(2*x))))