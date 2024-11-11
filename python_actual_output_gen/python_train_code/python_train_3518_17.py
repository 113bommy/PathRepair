for w in range(int(input())):
    a, b, n = (int(x) for x in input().split())
    u = 0
    while a <= n and b <= n:
        if u % 2:
            a += b
        else:
            b += a
        u += 1
    print(u)