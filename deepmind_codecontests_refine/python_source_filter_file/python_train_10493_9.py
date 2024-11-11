a,b,x = map(int,input().split())

import math

if x <= a*a*b*0.5:
  print(90-math.atan(x/b/b/a*2)*180/math.pi)
else:
  y = a*a*b-x
  print(90-math.atan(y/a/a/a*2)*180/math.pi)