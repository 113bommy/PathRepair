for _ in range(int(input())):
    x1, y1, x2, y2 = map(int, input().split())
    time = 0
    if (x2 - x1 == 0 or y2 - y1 == 0):
        print(abs(x2-x1) + abs(y2 - y1))
    else:
        print(abs(x2-x1)+abs(y2-y1-1)+3)