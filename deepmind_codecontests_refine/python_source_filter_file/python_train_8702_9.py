x1, y1, x2, y2 = map(int, input().split())
dx, dy = map(int, input().split())

if (x1-x2)%dx == 0 and (y1-y2)%dy == 0 and ((x1-x2)//dx)%dx == ((y1-y2)//dy)%2:
    print("YES")
else:
    print("NO")