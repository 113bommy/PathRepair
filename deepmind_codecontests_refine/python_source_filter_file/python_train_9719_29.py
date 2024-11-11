from math import sqrt as fuck
x,y,z=map(int,input().split())
a=int((fuck(x*y*z))//(x))
b=int((fuck(x*y*z))//(y))
c=int((fuck(x*y*z))//(y))
print(4*(a+b+c))