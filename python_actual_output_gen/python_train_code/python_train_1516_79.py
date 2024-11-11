x, y, z, t1, t2, t3 = map(int, input().split())
lift = abs(x - z) * t2 + abs(x - y) * t2 + 3 * t3
pesh = abs(x - y) * t1
print(lift, pesh)
if pesh < lift:
    print('NO')
else:
    print('YES')
