import math
a,b,c=map(int,input().split())
if a*b<(c-a-b)*(c-a-b) and c>a+b:
  print('Yes')
else:
  print('No')