for _ in range(int(input().strip())):
    x,n = map(int,input().strip().split())

    if n == 0:
        print(x)

    elif x%2  == 0:
        k = n%4
        if k == 1:
            print(x - n)
        elif k == 2:
            print(x + 1)
        elif k == 3:
            print(x + n + 1)
        else:
            print(x)

    else:
        k = n%4
        if k == 1:
            print(x + n)
        elif k == 2:
            print(x)
        elif k == 3:
            print(x - n - 1)
        else:
            print(x)