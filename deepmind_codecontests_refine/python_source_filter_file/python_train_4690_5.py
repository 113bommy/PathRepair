import math
n=int(input())
xli=list(map(float,input().split())
yli=list(map(float,input().split())
a=0
b=0
c=0
d=0
 
for x,y in zip(xli,yli):
    base = math.fabs(x-y)
    a += base
    b += base**2
    c += base**3
    if d < base : d = base
 
print(a)
print(b**(1/2))
print(c**(1/3))
print(d)