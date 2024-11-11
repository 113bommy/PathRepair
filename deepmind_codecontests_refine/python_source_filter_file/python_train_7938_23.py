n, m, Sx, Sy = map(int, input().split())


def Print(i, j):
    print((i+Sx-2) % n+1, (j+Sy-2) % m+1)


def solve(n, m, Sxy, Sy):
    for i in range(1, n):
        if i & 1:
            for j in range(1, m+1):
                Print(i, j)
        else:
            for j in range(m, 0, -1):
                Print(i, j)


solve(n, m, Sx, Sy)
