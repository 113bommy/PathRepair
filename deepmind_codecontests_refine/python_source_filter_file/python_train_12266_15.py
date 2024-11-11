f=lambda:[*map(int,input().split())]
n,x=f()
l=f()
d=[l[i+1]-l[i] for i in range(n-1)]
a=x-l[0]
from math import *
for i in d:
  a=gcd(a,i)
print(a)