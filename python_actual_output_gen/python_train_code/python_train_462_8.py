a, b, c = map(int, input().split())
if c == 0:
    if a == b:
        print('YES')
    else:
        print('NO')
else:
    if (b - a) % c == 0 and (b - 1) / c > 0:
        print('YES')
    else:
        print('NO')