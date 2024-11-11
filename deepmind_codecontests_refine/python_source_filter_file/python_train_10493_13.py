import math
a,b,x=map(int,input().split())
if x>a**2*b:
  print(math.atan(2*b/a-2*x/a**3)*180/math.pi)
else:
  print(math.atan(a*b**2/x/2)*180/math.pi)