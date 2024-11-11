import math

par = input()
# par = '10 0 0 0 0'

def dist(x1, y1, x2, y2):
    return math.sqrt((x1-x2)** 2 + (y1-y2)** 2)

def setap(R, x1, y1, x2, y2):
    d = dist(x1, y1, x2, y2)
    if d < R and d > 0:
        r = ( d + R ) / 2
        x = x2 - r / d * (x2 - x1)
        y = y2 - r / d * (y2 - y1)
    elif d == 0:
        x = x2 + R / 2
        y = y2
        r = R / 2
    else:
        r = R
        x = x1
        y = y1
    return [x,y,r]
    
    

par = list(map(int, par.split()))
R = par[0]
x1 = par[1]
y1 = par[2]
x2 = par[3]
y2 = par[4]

res = setap(R, x1, y1, x2, y2)
print(res[0],res[1], res[2])