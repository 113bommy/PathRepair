for i in range(int(input())):
    x, y = (int(x) for x in input().split())
    if x == 1 and x != y:
        print('NO')
    elif x <= 3 and abs(x-y) > 1:
        print('NO')
    else:
        print('YES')
