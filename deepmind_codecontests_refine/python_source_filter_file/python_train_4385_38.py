x, y, z, t1, t2, t3 = map(int, input().split())

a = abs(x - z) * t2 + abs(x - y) * t2 + 2 * t3
b = abs(x - y) * t1

if a < b:
    print('YES')
else:
    print('NO')