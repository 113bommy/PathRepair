while True:
    try:
        x1,y1,x2,y2,x3,y3,x4,y4 = map(float,input().split(','))
        p = (x3 - x4) * (y1 - y3) + (y3 - y4) * (x3 - x1)
        q = (x3 - x4) * (y2 - y3) + (y3 - y4) * (x3 - x2)
        r = (x1 - x2) * (y3 - y1) + (y1 - y2) * (x1 - x3)
        s = (x1 - x2) * (y4 - y1) + (y1 - y2) * (x1 - x4)
        if p * q < 0 and r * s < 0:
            print("YES")
        else:
            print("NO")
    except EOFError: break