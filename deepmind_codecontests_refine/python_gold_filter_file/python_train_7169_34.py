for i in range(int(input())):
    x1, y1, x2, y2, x3, y3, x4, y4 = map(float, input().split())
    det = abs((y1-y2) * (x3-x4) - (x1-x2) * (y3-y4))
    if det<1e-12 :
        print("YES")
    else:
        print("NO")