for _ in range(int(input())):
    x1, y1, z1 = map(int, input().split())
    x2, y2, z2 = map(int, input().split())
    if z2<=x1:
        points = 0
        x1 = x1-z2
        points+= min(z1, y2)
        print(points*2)
    else:
        z2 -= x1
        points = 0
        if z2<=z1:
            z1-=z2
            points = min(z1, y2)
            print(points*2)
        else:
            z2-=z1
            print(z2*2)