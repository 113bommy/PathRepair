import math
r,x1,y1,x2,y2 = input().split()
r = int(r)
x1 = int(x1)
y1 = int(y1)
x2 = int(x2)
y2 = int(y2)
s = math.sqrt((x1-x2)**2 + (y1-y2)**2)
rad = (s+r)/2
if s>0:
    si = (y2-y1)/s
    co = (x2-x1)/s
    x0 = x2 - (r+s)*co
    y0 = y2 - (r+s)*si
    ans1 = (x0+x2)/2
    ans2 = (y0+y2)/2
    if s>r:
        rad =r
        ans1 = x1
        ans2 = y1
    
if s == 0:
    ans1 = x1-r/2
    ans2 = y1
    rad = r/2
    
print(ans1,' ',ans2,' ',rad)