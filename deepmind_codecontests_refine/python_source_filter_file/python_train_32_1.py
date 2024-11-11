import math
n,x,y=map(int,input().split())
xx=max(0,math.floor(n*y/100)-x)
print(xx)