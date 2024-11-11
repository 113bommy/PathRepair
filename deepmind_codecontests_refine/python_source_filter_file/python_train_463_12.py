import math
r,x,y,a,b=map(int,input().split())
print(int(math.sqrt((a-x)*(a-x)+(b-y)*(b-y))/(2*r)))
