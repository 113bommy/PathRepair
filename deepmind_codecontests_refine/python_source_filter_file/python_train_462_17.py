from math import sqrt
r,x,y,X,Y = [int(i) for i in input().split()]

dist = sqrt((x-X)**2+(y-Y)**2)
print(int(dist/(2*r)))