t, s, x = map(int, input().split())
if x < t:
    print('YES')
else:
    if x == t + 1 and s != 1:
        print('NO')
    else:
        if (x - t) % s == 0 or (x - t - 1) % s == 0:
            print('YES')
        else:
            print('NO')