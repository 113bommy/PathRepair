a,b,x=map(int,input().split())
v=a*a*b/2
import math
k=(2*v-x)*2/(a*b)
g=2*x/(a*b)
if x<=v:
  print(math.atan(b/g)*180/math.pi)
else:
  print(math.atan(b/k)*180/math.pi)