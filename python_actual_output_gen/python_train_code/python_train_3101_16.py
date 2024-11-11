x, y = list(map(int, input().split()))
if x - y < -2:
    print('NO')
else:
    x = x - y + 1
    if y == 0:
        print('NO')
    elif y == 1:
        if x > 1:
            print('NO')
        else:
            print('YES')
    elif x % 2 == 0:
        print('YES')
    else:
        print('NO')