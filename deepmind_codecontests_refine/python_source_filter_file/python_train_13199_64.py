n=int(input())
import math
a=math.floor(math.sqrt(n))
while a>0:
  if n%a==0:break
  a-=1

print(a+n//a)
