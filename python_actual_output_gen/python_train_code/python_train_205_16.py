a = list( list(map(int,input().split())) for _ in range(3))
for x in range(10**5):
    a[0][0] = x
    a[1][1] = sum(a[0]) - sum(a[1])
    a[2][2] = sum(a[0]) - sum(a[2])
    t = 0
    for i in range(3):
        t+= a[i][i]
    s = 0
    check = 0
    for i in range(3):
        s = 0
        for j in range(3):
            s+= a[j][i]
        if s==t:
            check+=1
    if t == sum(a[0]) and check == 3:
        for j in range(3):
            print(*a[j])
        exit()
    a[1][1] = 0
    a[2][2] = 0
        