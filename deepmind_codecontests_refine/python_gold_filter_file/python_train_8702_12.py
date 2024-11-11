x1, y1, x2, y2 = map(int, input().split())

x, y = map(int, input().split())
dx, dy = abs(x2 - x1), abs(y2 - y1)

if dx % x == 0 and dy % y == 0 and (dx // x + dy // y) % 2 == 0:
    print('YES')
else:
    print('NO')