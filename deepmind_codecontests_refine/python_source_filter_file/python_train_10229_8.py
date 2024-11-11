for _ in range(int(input())):
    a, b, n = map(int, input().split())
    res = 0
    while max(a, b) < n:
        if a > b:
            b += a
        else:
            a += b
        res += 1
    print(res)