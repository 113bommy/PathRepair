import math
a,b,x,y=map(int,input().split())
sum=0
o=math.gcd(x,y)
x=x/o
y=y/o
print(min(a//x,b//y))
