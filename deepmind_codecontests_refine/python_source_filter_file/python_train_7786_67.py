s = int(input())
x1, y1 = 0, 0
x2, y2 = 10**9, 1
x3 = s % (10**9)
y3 = (s+x3) // (10**9)
print(x1,y1,x2,y2,x3,y3)