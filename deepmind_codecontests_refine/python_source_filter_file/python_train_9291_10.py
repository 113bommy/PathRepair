for _ in range(int(input())):
    n, k = map(int, input().split())
    a = [[0]*n for i in range(n)]
    i = 0
    j = 0
    if k % n == 0:
        print(0)
    else:
        print(2)
    while k:
        k -= 1
        a[i][j] = 1
        i += 1
        j = (j+1) % n
        if i == n:
            i = 0
            j = (j+1) % n
    for i in a:
        print(*i)
