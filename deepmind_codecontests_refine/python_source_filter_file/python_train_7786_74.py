S = int(input())
x1 = 0
y1 = 0
x2 = 10**9
y2 = 1
x3 = (x2-S)%x2
y3 = S//x2+1
print(x1,y1,x2,y2,x3,y3)
