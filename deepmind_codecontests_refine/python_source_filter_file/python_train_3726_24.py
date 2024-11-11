n = int(input())
p = []

for _ in range(n):
    x,y = map(int, input().split())
    p.append([x,y])

import math
import itertools

if n == 2:
    print(math.sqrt((p[0][0]-p[1][0])**2 + (p[0][1]-p[1][1])**2)/2)
    exit()

def rad(v):
    p1 = v[0]
    p2 = v[1]
    p3 = v[2]
    x1 = p1[0]
    y1 = p1[1]
    x2 = p2[0]
    y2 = p2[1]
    x3 = p3[0]
    y3 = p3[1]
    
    px = (x1-x3)*(y1**2-y2**2+x1**2-x2**2)-(y1-y2)*(y1**2-y3**2+x1**2-x3**2)
    if (2*(y1-y3)*(x1-x2)-2*(y1-y2)*(x1-x3)) == 0:
        return None
    px = px / (2*(y1-y3)*(x1-x2)-2*(y1-y2)*(x1-x3))
    
    py = (x1-x3)*(x1**2-x2**2+y1**2-y2**2)-(x1-x2)*(x1**2-x3**2+y1**2-y3**2)
    if (2*(x1-x3)*(y1-y2)-2*(x1-x2)*(y1-y3)) == 0:
        return None
    py = py / (2*(x1-x3)*(y1-y2)-2*(x1-x2)*(y1-y3))

    return [px,py,(x1-px)**2+(y1-px)**2]

ans = 10**13

for v in itertools.combinations(p,2):
    p1 = v[0]
    p2 = v[1]
    px = (p1[0]+p2[0])/2
    py = (p1[1]+p2[1])/2
    rr = (p1[0]-p2[0])**2+(p1[1]-p2[1])**2
    rr = rr /4
    chk = True
    for i in range(n):
        if (p[i][0]-px)**2+(p[i][1]-py)**2 > rr + 2*10**(-6):
            chk = False
    if chk:
        ans = min(ans,rr**0.5)

for v in itertools.combinations(p,3):
    d = rad(v)
    if d == None:
        continue
    chk = True
    for i in range(n):
        if (p[i][0]-d[0])**2+(p[i][1]-d[1])**2 > d[2] + 2*10**(-6):
            chk = False
    if chk:
        ans = min(ans,d[2]**0.5)

print(ans)
