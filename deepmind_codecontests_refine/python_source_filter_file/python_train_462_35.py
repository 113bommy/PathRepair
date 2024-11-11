r,x,y,a,b = list(map(int,input().split()))

import math
#print((x-a)**2 + (y-b)**2,2*r)
dist = math.ceil(math.sqrt(((x-a)**2 + (y-b)**2))/(4*r**2))
print(dist)