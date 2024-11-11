import math
for _ in range(int(input())):
 l,r,d = map(int,input().split())
 if l>d:
  print(d)
 elif r<d:
  print(d)
 elif r==d:
  print(d*2)
 elif r%d !=0:
  print(math.ceil(r/d)*2)
 else:
  print(r+d)