from math import sqrt
x1,y1,r1 = map(int,input().split())
x2,y2,r2 = map(int,input().split())

d = (x1-x2)**2 + (y1-y2)**2
d = sqrt(d)

if d > r1+r2:
    print((d-r1-r2)/2)
elif abs(r1-r2)<=d<=r1+r2:
    print(0)
else:
    print((max(r1,r2)-d+min(r1,r2))/2)



