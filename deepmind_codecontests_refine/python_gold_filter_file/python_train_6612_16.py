[xr, yr,] = map(int, input().split())
[x, y] = map(int, input().split())
xdistance = abs(x - xr)
ydistance = abs(y - yr)
if (xdistance > ydistance):
    a = xdistance - ydistance
    print (abs(ydistance + a))
if (xdistance < ydistance):
    a = ydistance - xdistance
    print (abs(xdistance + a))
if (xdistance == ydistance):
    print (xdistance)