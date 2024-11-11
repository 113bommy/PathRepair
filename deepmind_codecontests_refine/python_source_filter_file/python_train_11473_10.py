import math
for _ in[0]*int(input()):
  a,b=map(int,input().split())
  print('In'*(math.gcd(a,b)>2)+'finite')