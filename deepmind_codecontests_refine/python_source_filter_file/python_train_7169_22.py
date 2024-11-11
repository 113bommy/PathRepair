for _ in range(int(input())):
    x1, y1, x2, y2, x3, y3, x4, y4 = map(float, input().split())
    print(["NO","YES"][abs((x1 - x2) * (y3 - y4) - (x3 - x4) * (y1 - y2)) < 10e-3])
