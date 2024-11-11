from math import ceil
r,x,y,x1,y1 = list(map(int, input().split()))
r = r**2
dist = (((x1-x)**2) + ((y1-y)**2))**0.5
print(ceil(dist/r))
