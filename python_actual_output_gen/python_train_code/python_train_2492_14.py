for _ in range(int(input())):
    n,m,a,b = map(int,input().split())
    if a > n / 2:
        a = n - a - 1
    if b > m / 2:
        b = m - b - 1
    if (n - a - 1) * m >= (m - b - 1) * n:
        print((n - a - 1) * m)
    else:
        print((m - b - 1) * n)