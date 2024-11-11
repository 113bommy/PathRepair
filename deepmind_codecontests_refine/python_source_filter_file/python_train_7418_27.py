t = int(input())

for i in range(t):
    n = int(input())

    if( n < 31 ):
        print('NO')
    else:
        print('YES')
        d = n - 30
        if n == 36:
            print(14, 6, 15, 1)
        if n == 44:
            print(10, 14, 15, 5)
        elif n == 40:
            print(10, 14, 15, 1)
        else:
            print('6 10 14',d)