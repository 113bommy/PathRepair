x1, y1, x2, y2 = map(int, input().split(' '))
x3, y3, x4, y4 = map(int, input().split(' '))
x5, y5, x6, y6 = map(int, input().split(' '))

b = True
if x3 <= x1 and x2 <= x4 and x5 <= x1 and x2 <= x6:
    if y3 <= y1 and y2 <= y6 and y4 >= y5 or y5 <= y1 and y2 <= y3 and y5 >= y4:
        b = False
if y3 <= y1 and y2 <= y4 and y5 <= y1 and y2 <= y6:
    if x3 <= x1 and x2 <= x6 and x4 >= x5 or x5 <= x1 and x2 <= x3 and x5 >= x4:
        b = False
if x3 <= x1 and y3 <= y1 and x4 >= x2 and y4 >= y2:
    b = False
if x5 <= x1 and y5 <= y1 and x6 >= x2 and y6 >= y2:
    b = False

print("YES") if b == True else print("NO")