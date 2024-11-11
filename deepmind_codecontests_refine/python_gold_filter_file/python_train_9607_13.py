for _ in range(int(input())):
    r, c = map(int, input().split())
    a = []
    b = []
    [a.append(list(input())) for i in range(r)]
    for i in range(r - 1):
        for j in range(c):
            if j == 0 and int(a[i][j]):
                a[i][j] = (int(a[i][j]) + 1) % 2
                a[i + 1][j] = (int(a[i + 1][j]) + 1) % 2
                a[i + 1][j + 1] = (int(a[i + 1][j + 1]) + 1) % 2
                b.append([i + 1, j + 1, i + 2, j + 1, i + 2, j + 2])
            elif int(a[i][j]):
                a[i][j] = (int(a[i][j]) + 1) % 2
                a[i + 1][j] = (int(a[i + 1][j]) + 1) % 2
                a[i + 1][j - 1] = (int(a[i + 1][j - 1]) + 1) % 2
                b.append([i + 1, j + 1, i + 2, j + 1, i + 2, j])
    for j in range(c - 1):
        i = r - 1
        if int(a[-1][j]):
            b.append([i, j + 1, i + 1, j + 1, i + 1, j + 2])
            b.append([i, j + 1, i, j + 2, i + 1, j + 1])
            b.append([i + 1, j + 2, i + 1, j + 1, i, j + 2])
    if int(a[-1][-1]):
        i = r - 1
        j = c - 1
        b.append([i + 1, j + 1, i, j + 1, i + 1, j])
        b.append([i, j + 1, i + 1, j + 1, i, j])
        b.append([i + 1, j, i + 1, j + 1, i, j])

    print(len(b))
    for i in b:
        print(*i)
