import math
s=0
m=10
for i in range(5):
  a =int(input())
  s+=math.ceil(a/10)*10
  if a%10 !=0:
    m = min(m,a%10)
print(s-m)