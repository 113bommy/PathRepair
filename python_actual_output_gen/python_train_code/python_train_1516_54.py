x, y, z, t1, t2, t3 = map(int, input().split())
if abs(x - y) * t1 < (abs(x - z) + abs(x - y)) * t2 + 4 * t3:
    print('NO')
else:
    print('YES')