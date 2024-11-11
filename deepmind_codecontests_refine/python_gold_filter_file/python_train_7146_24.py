import sys
from math import sqrt
r,x1,y1,x2,y2=input().split()
r=float(r)
x1=float(x1)
x2=float(x2)
y1=float(y1)
y2=float(y2)
ch=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)-r*r
if ch>=0:
    print(x1,y1,r)
    sys.exit(0)
d=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))
if d==0:
    print(x1+r/2,y1,r/2)
    sys.exit(0)
cos=(x1-x2)/d
sin=(y1-y2)/d
x=(x1+r*(cos)+x2)/2
y=(y1+r*(sin)+y2)/2
rans=sqrt((x-x2)*(x-x2)+(y2-y)*(y2-y))
print(x,y,rans)
