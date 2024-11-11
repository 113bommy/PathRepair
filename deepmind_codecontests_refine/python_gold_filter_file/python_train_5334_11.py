t = int(input())
for i in range(t):
    a, b, c, d = [int(j) for j in input().split()]
    x, y, x1, y1, x2, y2 = [int(j) for j in input().split()]
    c1 = x1 <= x - a + b <= x2
    c2 = y1 <= y - c + d <= y2
    if x1 == x == x2 and abs(a) + abs(b) > 0:
        print('NO')
    elif y1 == y == y2 and abs(c) + abs(d) > 0:
        print('NO')
    elif c1 and c2:
        print('YES')
    else:
        print('NO')
