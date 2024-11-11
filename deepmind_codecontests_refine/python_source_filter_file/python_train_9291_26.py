T = int(input())
for t in range(T):
    n, k = (int(i) for i in input().split())
    a = [[0 for j in range(n)] for i in range(n)]

    i, j = 0, 0
    if k > 0:
        a[i][j] = 1
    for l in range(k - 1):
        j += 1
        if j == n:
            j = 0
            i += 1
        if i == n:
            i = 0
        i += 1
        if i == n:
            i = 0
        a[i][j] = 1

    if k % n == 0:
        print(0)
    else:
        print(2)

    for i in range(n):
        for j in range(n):
            print(a[i][j])
        print()
