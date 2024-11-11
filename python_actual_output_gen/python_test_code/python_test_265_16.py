t = int(input())
x1 = x2 = y1 = y2 = 0
while t:
    t = t-1
    a, x, y = [int(x) for x in input().split()]
    if a == 1:
        x1 = x1+x
        y1 = y1+y
    else:
        x2 = x2+x
        y2 = y2+y
if x1 >= y1:
    print("ALIVE")
else:
    print("DEAD")
if x2 >= y2:
    print("ALIVE")
else:
    print("DEAD")
