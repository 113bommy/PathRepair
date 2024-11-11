for _ in range(int(input())):
    x1, y1, x2, y2, x3, y3, x4, y4 = map(float, input().split())
    ab = [x2 - x1, y2 - y1]
    cd = [x4 - x3, y4 - y3]
    if abs(ab[0] * cd[1] - ab[1] * cd[0]) > 0.00000000001:
        print('NO')
    else:
        print('YES')