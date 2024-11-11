from math import sqrt
n, vb, vs = [float(i) for i in input().split()]
mi = 10**18
ix = 1
x = [float(i) for i in input().split()]
x2, y2 = [float(i) for i in input().split()]
for i in range(1,len(x)):
    l = sqrt((x2-x[i])**2+(y2-0)**2)
    if (x[i]/vb) + (l / vs) < mi:
        mi = (x[i]/vb) + (l / vs)
        ix = i + 1
print(ix)