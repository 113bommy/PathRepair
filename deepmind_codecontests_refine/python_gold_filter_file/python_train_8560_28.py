for _ in range(int(input())):
    x, n, m = map(int, input().split())
    b = x
    w = 0
    if b - (10*m) <= 0:
        print('YES')
    else:
        for i in range(n):
            b = (b // 2) + 10
            # print(b)
            if b <= (10 * m):
                w = 1
                break
        if w == 1:
            print('YES')
        else:
            print('NO')