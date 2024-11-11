n = int(input())
x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
x3, y3 = map(int, input().split())
if (x2 < x1 and x3 < x1 and y2 < y1 and y3 < y1) or (x2 < x1 and x3 < x1 and y2 > y1 and y3 > y1) or (x2 > x1 and x3 > x1 and y2 < y1 and y3 < y1) or (x2 > x1 and x3 > x1 and y2 > y1 and y3 > y1) and not((abs(x1 - x3) == abs(y1 - y3)) or (x3 == x1 or y3 == y1)):
    print('YES')
else:
    print('NO')