import math 

l = [(int)(s) for s in input().split(" ")]

x1 = (int)(l[0])
y1 = (int)(l[1])
x2 = (int)(l[2])
y2 = (int)(l[3])

maxX = (x2 - x1) // 2 + 1
dy = y2 - y1 + 1
yy = (dy + 1) // 2

print((int)(maxX * yy + (maxX - 1) * (dy - yy)))
