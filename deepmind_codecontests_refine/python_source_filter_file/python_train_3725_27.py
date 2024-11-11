import math

a,b,h,m=map(int,input().split())
x = abs(math.pi*(60*h-m)/360)
ans = ( a**2 + b**2 - math.cos(x)*2*a*b ) **0.5
print(ans)
