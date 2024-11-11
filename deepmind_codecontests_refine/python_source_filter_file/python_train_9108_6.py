n = int(input())
if (n == 1):
    print(-1)
elif (n == 2):
    x1, y1 = map(int, input().split())
    x2, y2 = map(int, input().split())
    if (x1 == x2) or (y1 == y2):
        print(-1)
    else:
        print(abs(x2 - x1) * abs(y2 - y1))
else:
    x1, y1 = map(int, input().split())
    x2, y2 = map(int, input().split())
    x3, y3 = map(int, input().split())
    if (x1 == x2) or (y1 == y2):
        if (x1 == x3) or (y1 == y3):
            print(abs(x3 - x1) * abs(y3 - y1))
        else:
            print(abs(x3 - x2) * abs(y3 - y2))
    else:
        print(abs(x2 - x1) * abs(y2 - y1))
