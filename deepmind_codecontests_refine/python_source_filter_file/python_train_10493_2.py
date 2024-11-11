from math import atan2,degrees
a,b,x=map(int,input().split())
if 2*x<=b*a*a:
  print(90-degrees(atan2(2*x,a*b*b)))
else:
  print(90-degrees(atan2(a*a*a,2*(a*a*b-x)))
