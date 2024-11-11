import math
a, b, x = map(int, input().split())
if a*a*b <= 2*x:
  print(math.degrees(math.atan2(a*b*b,2*x)))
else:
  print(math.degrees(math.atan2(2*(a*a*b-x),a**3)))