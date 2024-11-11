r1, r2 = map(int, input().split())
c1, c2 = map(int, input().split())
d1, d2 = map(int, input().split())
m = min(r1, r2, c1, c2, d1, d2)
i = 1
while 1:
    x1 = i
    x2 = c1 - x1
    y1 = r1 - x1
    y2 = r2 - x2
    i += 1
    if (x1<=0) | (x2<=0) | (y1<=0) | (y2<=0) | (x1>9) | (x2>9) | (y1>9) | (y2>9) | (x1 + y2 != d1) | (x2 + y1 != d2) | (x1 + x2 != c1) | (y2 + y1 != c2) | (x1 + y1 != r1) | (x2 + y2 != r2):
        if i >= 9:
            print('-1')
            break
        continue
    else:
        if (x1==x2) | (x1==y1) | (y1==y2) | (x1==y2) | (x2==y1) | (x2==y2):
            print('-1')
        else:
            print(x1, y1)
            print(x2, y2)
        break








   # if m == c1:
   #      x1 = m - i
   #      x2 = c1 - x1
   #      y1 = r1 - x1
   #      y2 = c2 - y1
   #  elif m == c2:
   #      y1 = m - i
   #      y2 = c2 - y1
   #      x1 = r1 - y1
   #      x2 = c1 - x1
   #  elif m == r1:
   #      x1 = m - i
   #      x2 = c1 - x1
   #      y1 = r1 - x1
   #      y2 = c2 - y1
   #  elif m == r2:
   #      x2 = m - i
   #      x1 = c1 - x2
   #      y1 = r1 - x1
   #      y2 = c2 - y1
   #  elif m == d1:
   #      x1 = m - i
   #      x2 = c1 - x1
   #      y1 = r1 - x1
   #      y2 = c2 - y1
   #  elif m == d2:
   #      y1 = m - i
   #      y2 = c2 - y1
   #      x1 = r1 - y1
   #      x2 = c1 - x1
