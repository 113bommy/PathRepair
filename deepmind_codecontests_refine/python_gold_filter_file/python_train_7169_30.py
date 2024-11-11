n = int(input())
for i in range(n):
    x1, y1, x2, y2, x3, y3, x4, y4 = map(float, input().split())
    if x1 == x2 and x3 == x4:
        print("YES")
    elif x1 == x2 or x3 == x4:
        print("NO")
    elif abs((y2 - y1) / (x2 - x1) - (y4 - y3) / (x4 - x3)) < 1e-10:
        print("YES")
    else:
        print("NO")