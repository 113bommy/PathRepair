def isavailable(nb, lst):
    for i in range(n):
        for j in range(m):
            if lst[i][j] > nb[i][j]:
                print('NO')
                return 0
            else:
                lst[i][j] = nb[i][j]
    print('YES')
    for i in range(n):
        for j in range(m):
            print(lst[i][j], end=' ')
        print()
    return 0


t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    lst = []
    for i in range(n):
        col = list(map(int, input().split()))
        lst.append(col)
    nb = []
    for i in range(n):
        col = [0] * m
        nb.append(col)
    for i in range(n):
        for j in range(m):
            if (i == 0 or i == (n - 1)) and (j == 0 or j == n - 1):
                nb[i][j] = 2
            elif i == 0 or i == n - 1 or j == 0 or j == n - 1:
                nb[i][j] = 3
            else:
                nb[i][j] = 4
    a = isavailable(nb, lst)
