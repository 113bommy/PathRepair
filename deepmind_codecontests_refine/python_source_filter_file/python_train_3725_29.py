import math
a,b,h,m=map(int,input().split())
angle=abs(m*6-(h*30+m/60*30))
print(math.sqrt(a*a+b*b-2*a*b*math.cos(angle/180*pi)))
