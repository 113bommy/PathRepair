import math
n, R, r=  list(map(int, input().split()))
if (n==1):
  if (r<=R):
    print ("YES")
  else:
    print ("NO")
elif (n==2):
  if (2*r<=R):
    print ("YES")
  else:
    print ("NO")
else:
  a= r/round(math.sin(math.pi/n),2)
  if (a <= (R-r)):
    print ("YES")
  else:
    print ("NO")