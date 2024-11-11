x1, y1, x2, y2 = map(int, input().split())
x, y = map(int, input().split())
a = abs(x1 - x2)
b = abs(y1 - y2)
if a == 0 and b == 0:
    print("YES")
elif a == 0:
    if b % y != 0:
        print("NO")
    elif (b // y) % 2 == 0:
        print("YES")
    else:
        print("NO")
elif b == 0:
    if a % x != 0:
        print("NO")
    elif (a // x) % 2 == 0:
        print("YES")
    else:
        print("NO")
else:
    if a % x != 0 or b % y != 0:
        print("NO")
    elif (a // x) % 2 == (b // y) % 2:
        print("YES")
    else:
        print("NO")
