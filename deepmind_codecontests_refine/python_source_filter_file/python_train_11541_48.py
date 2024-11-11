import math
a,b,c=map(int,input().split())
if math.gcd(a,b)%c==0:
  print('YES')
else:
  print('NO')