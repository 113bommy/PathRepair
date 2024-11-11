for _ in range(int(input())):
    n, m = map(int, input().split())
    a = [['W'] * m for _ in range(n)]
    for i in range(n):
        for j in range(0, (m // 2) * 2, 2):
            a[i][j] = 'B'
    if m % 2 > 0:
        for i in range(0, n, 2):
            a[i][m - 1] = 'B'
    if (n % 2 == 0 and m % 2 > 0) or m % 2 == 0:
        a[n - 1][1] = 'B'
    for i in range(n):
        print(' '.join(a[i]))
