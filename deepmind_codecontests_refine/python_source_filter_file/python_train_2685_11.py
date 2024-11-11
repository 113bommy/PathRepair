n,m=map(int,input().split())
a=list(map(int,input().split()))
b=[a[i]//2 for i in range(n)]
from fractions import gcd
from functools import reduce
def lcm(x,y):
  return (x*y)//gcd(x,y)
x=reduce(lcm,b,1)
y=reduce(lcm,a,1)
if x>m:
  print(0)
else:
  z=(m-x)//y+1
  for i in b:
    if (x//i)%2==1:
      z=0
      break
  print(z)