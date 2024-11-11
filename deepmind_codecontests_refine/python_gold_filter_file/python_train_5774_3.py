n = int(input())
a = []
for i in range(n):
    a.append(list(input()))
flag = False
if n == 1:
    print('YES')
elif n == 2:
    c = 0
    if a[0][1] == 'o':
        c += 1
    if a[1][0] == 'o':
        c += 1
    if c % 2 == 1:
        flag = True
    c = 0
    if a[0][0] == 'o':
        c += 1
    if a[1][1] == 'o':
        c += 1    
    if c % 2 == 1:
        flag = True
    if flag:
        print('NO')
    else:
        print('YES')
else:
    c = 0
    if a[0][1] == 'o':
        c += 1
    if a[1][0] == 'o':
        c += 1
    if c % 2 == 1:
        print('NO')
        exit()            
    for i in range(1, n - 1):
        if a[0][i - 1] == 'o':
            c += 1
        if a[0][i + 1] == 'o':
            c += 1
        if a[1][i] == 'o':
            c += 1
        if c % 2 == 1:
            print('NO')
            exit()
    if a[n - 1][1] == 'o':
        c += 1
    if a[n - 2][0] == 'o':
        c += 1
    if c % 2 == 1:
        print('NO')
        exit()
    #----------------------
    for i in range(1, n - 1):
        c = 0
        if a[i][1] == 'o':
            c += 1
        if a[i - 1][0] == 'o':
            c += 1
        if a[i + 1][0] == 'o':
            c += 1
        if c % 2 == 1:
            print('NO')
            exit()            
        for j in range(1, n - 1):
            c = 0
            if a[i][j - 1] == 'o':
                c += 1
            if a[i][j + 1] == 'o':
                c += 1
            if a[i - 1][j] == 'o':
                c += 1
            if a[i + 1][j] == 'o':
                c += 1
            if c % 2 == 1:
                print('NO')
                exit()
        c = 0
        if a[i][n - 2] == 'o':
            c += 1
        if a[i - 1][n - 1] == 'o':
            c += 1
        if a[i + 1][n - 1] == 'o':
            c += 1
        if c % 2 == 1:
            print('NO')
            exit()
    #---------------------------
    if a[n - 2][0] == 'o':
        c += 1
    if a[n - 1][1] == 'o':
        c += 1
    if c % 2 == 1:
        print('NO')
        exit()            
    for i in range(1, n - 1):
        if a[n - 1][i - 1] == 'o':
            c += 1
        if a[n - 1][i + 1] == 'o':
            c += 1
        if a[n - 2][i] == 'o':
            c += 1
        if c % 2 == 1:
            print('NO')
            exit()
    if a[n - 1][1] == 'o':
        c += 1
    if a[n - 2][0] == 'o':
        c += 1
    if c % 2 == 1:
        print('NO')
        exit()
    print('YES')
