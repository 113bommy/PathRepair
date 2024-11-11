import math
W=int(input())
for i in range(W):
  n=int(input())
  Pi=2*math.asin(1)
  O=(2*n-2)/(2*n)
  E=1/2
  I=0
  for m in range(n//2-1):
      E=O-E
      c=math.sin(Pi*E)
      I+=c
  print(2*I+1)