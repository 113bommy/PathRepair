from math import *
n=int(input())
r=sqrt(1+8*n)
x=(-1+r)/2
y=(-1-r)/2
x1=int(x)
y1=int(y)
if (x==y or x1==y1) and (x>0 or y>0):
    print('YES')
else:
    print('NO')
