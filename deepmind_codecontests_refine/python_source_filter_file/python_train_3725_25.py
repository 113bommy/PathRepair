a,b,h,m=map(int,input().split())
import math
t=abs((math.pi*h/6)-(math.pi*m/30))
r=(a**2-2*a*b*math.cos(t)+b**2)**0.5
print(r)
