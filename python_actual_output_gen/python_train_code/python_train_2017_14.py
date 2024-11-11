size = int(input())
x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
x3, y3 = map(int, input().split())

if (y2 - y1) * (y3 - y1) > 0 and (x2 - x1) * (x3 - x1) and x1 + y1 != x3 + y3:
    print('YES')
else:
    print('NO')