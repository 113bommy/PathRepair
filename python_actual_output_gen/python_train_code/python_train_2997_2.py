x1, y1, x2, y2 = map(int, input().split())
x, y = map(int, input().split())

if abs(x2 - x1) % x == 0 and abs(y2 - y1) % y == 0 and abs(x2 - x1) % 2 == abs(y2 - y1) % 2:
    print("YES")
else:
    print("NO")
    
