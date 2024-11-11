for _ in range(int(input())):
    x1, y1 = input().split()
    y1 = int(y1)
    x2, y2 = input().split()
    y2 = int(y2)
    lx1 = len(x1)
    lx2 = len(x2)
    if lx1 + y1 > lx2 + y2:
        print(">")
    elif lx1 + y1 < lx2 + y2:
        print("<")
    else:
        if lx1 >= lx2:
            x1 += "0" * (lx1 - lx2)
        else:
            x2 += "0" * (lx2 - lx1)
        if x1 > x2:
            print(">")
        elif x1 == x2:
            print("=")
        else:
            print("<")