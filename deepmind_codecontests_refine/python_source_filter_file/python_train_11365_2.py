n = int(input())
a = str(input())
if n == 1:
    print(a)
else:
    b, c = 0, 0
    res = 1e100005

    pos1 = int(n / 2)
    pos2 = int(n / 2)
    pos3 = int(n / 2) + 1
    pos4 = int(n / 2) - 1

    while pos1 < n and a[pos1] == '0':
        pos1 += 1
    while pos3 < n and a[pos3] == '0':
        pos3 += 1
    while pos2 >= 0 and a[pos2] == '0':
        pos2 -= 1
    while pos4 >= 0 and a[pos4] == '0':
        pos4 -= 1

    if pos1 < n and a[pos1] != '0':
        b = int(a[0:pos1])
        if pos1 != n - 1:
            c = int(a[pos1:])
        else:
            c = int(a[n - 1])
        res = min(res, b + c)

    if pos2 >= 0 and a[pos2] != '0':
        if pos2 != 0:
            b = int(a[0:pos2])
        else:
            b = 0
        c = int(a[pos2:])
        res = min(res, b + c)

    if pos3 < n and a[pos3] != '0':
        b = int(a[0:pos3])
        if pos3 != n - 1:
            c = int(a[pos3:])
        else:
            c = int(a[n - 1])
        res = min(res, b + c)

    if pos4 >= 0 and a[pos4] != '0':
        if pos4 != 0:
            b = int(a[0:pos4])
        else:
            b = 0
        c = int(a[pos4:])
        res = min(res, b + c)

    if a[n - 1] == '0':
        res = min(int(a[:n - 1]), int(res))

    print(int(res))