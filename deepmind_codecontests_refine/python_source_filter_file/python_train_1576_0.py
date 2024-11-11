import math
n , r = map(int,input().split())
x = 360/n
y = (180-x)/2
res = abs(math.sin(math.pi*x/180))/abs(2*abs(math.sin(math.pi*y/180))-math.sin(math.pi*x/180))
print(res)
