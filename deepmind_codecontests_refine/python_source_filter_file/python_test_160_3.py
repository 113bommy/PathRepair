for _ in range(int(input())):
    n, m, rb, cb, rd, cd = map(int, input().split())
    t = 0
    r = 1
    c = 1
    while not (rb==rd or cb == cd):
        t += 1
        if rb == m or rb == 0:
            r = -r
        if cb == n or cb == 0:
            c = -c
        rb += r
        cb += c
    print(t)
