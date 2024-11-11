r, x1, y1, x2, y2 = input().split()
r = int(r)
x1 = int(x1)
y1 = int(y1)
x2 = int(x2)
y2 = int(y2)
ar = ((x1 - x2)**2 + (y1 - y2)**2)**0.5
if(ar > r):
     print(x1, y1, r, sep = ' ')
     exit (0)
if(ar == 0):
     print((x1 + x1 + r) / 2, y1, r / 2, sep = ' ')
     exit (0)
rr = ar + r
x3 = x2 + (x1 - x2) * rr / ar
y3 = y2 + (y1 - y2) * rr / ar
print((x3 + x2) / 2, (y3 + y2) / 2, rr / 2, sep = ' ')