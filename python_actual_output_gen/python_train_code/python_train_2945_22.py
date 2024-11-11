for _ in range(int(input())):
    x, n, m = map(int, input().split())
    b = x
    t = 0
    if b % 10 <= m:
        print('YES')
    else:
        for i in range(n):
            b = (b // 2) + 10
            # print(b)
            if b <= (10 * m):
                t = 1
                break
        if t == 1:
            print('YES')
        else:
            print('NO')