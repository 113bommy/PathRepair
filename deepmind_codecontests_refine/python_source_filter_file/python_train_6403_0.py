from math import *
n = int(input())
dx1 = 0
dx2 = 0
dy1 = 0
dy2 = 0
a = []
for i in range(n):
    x,y = [int(x) for x in input().split()]
    a.append([x,y,i])
a.sort(key = lambda item: atan2(item[1],item[0]))
a.append(a[0])
dx1 = abs(a[0][0]*a[1][0]+a[0][1]*a[1][1])
dy1 = abs(a[0][0]*a[1][1]-a[1][0]*a[0][1])
minx = abs(dx1)
miny = abs(dy1)
min1,min2 = a[0][2],a[1][2]
for i in range(1,len(a)):
    dx2 = abs(a[i-1][0]*a[i][0]+a[i-1][1]*a[i][1])
    dy2 = abs(a[i-1][0]*a[i][1]-a[i][0]*a[i-1][1])
    if (dx2*miny-dy2*minx)>0:
        min1,min2=a[i-1][2],a[i][2]
        minx = dx2
        miny = dy2
print(min1+1,min2+1)

        









































    
    
