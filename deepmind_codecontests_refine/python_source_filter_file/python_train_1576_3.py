import math
n,r=map(int,input().split())
num=22*(n-2)
dem=14*n
#c=num/dem
#k=math.acos(c)
#ans=(r*k)/(1-k)
ans=(r*math.cos(num/dem))/(1-math.cos(num/dem))
print(ans)
