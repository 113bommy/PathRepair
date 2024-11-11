import math
t=int(input())
while(t>0):
  t=t-1
  n=int(input())
  x=math.floor(n/2)
  sum=(x*(x+1)*(2*x+1))/6
  print(int(sum*8))

