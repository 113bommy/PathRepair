import math
n,k = map(int,input().split())
a=1; b=-1; c = -2*(n+k)
d = (b**2) - (4*a*c)
sol1 = (-b-math.sqrt(d))/(2*a)
sol2 = (-b+math.sqrt(d))/(2*a)
#print(sol1,sol2)
if(sol1>sol2):
    print(abs(int(sol1)-n))
else:
    print(abs(int(sol2)-n))