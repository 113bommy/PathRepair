for i in range(int(input())):
    n, m = map(int, input().split())
    a = []
    d = 0
    for i in range(n):
        b = list(map(int, input().split()))
        a.append(b)
    #print(a)
    for i in range(n):
        for j in range(m):
            e = 4
            if(i == 0 or i == n-1):
                e -= 1
            if(j == 0 or j == n-1):
                e -= 1
            if(a[i][j] > e):
                d = 1
            else:
                a[i][j] = e
    if(d == 1):
        print('NO')
    else:
        print('YES')
        for i in range(n):
            print(*a[i])
    