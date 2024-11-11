x1, y1, x2, y2 = input().split()
x1, y1, x2, y2 = int(x1), int(y1), int(x2), int(y2)
x, y = input().split()
x, y = int(x), int(y)

if (x2 - x1) % x == 0 and (y2 - y1) % y == 0:
    if ((x2 - x1) / x)%2 == ((y2 - y1) / y)%2 :
        print("YES")
    else:
        print("NO")
else:
    print("NO")