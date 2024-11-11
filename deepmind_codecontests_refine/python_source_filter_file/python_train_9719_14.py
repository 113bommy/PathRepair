x,y,z=map(int,input().split())
from math import sqrt
a=sqrt(x*y/z)
b=sqrt(y*z/x)
c=sqrt(x*z/y)
print(4*(a+b+c))