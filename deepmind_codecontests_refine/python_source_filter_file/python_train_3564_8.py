t = int(input())

for i in range(t) :
    n = int(input())
    a = [int(x) for x in input().split()]
    mx = [0] * n
    mn = [0] * n
    mx[0] = mn[0] = a[0]
    for i in range(1 , n) :
        mx[i] = max(a[i] , mx[i-1])
        mn[i] = min(a[i] , mx[i-1])
    b = [int(x) for x in input().split()]
    if a[0] != b[0] :
        print('NO')
    else :
        check = True
        for i in range(1 , n) :
            if b[i] > a[i] and mx[i - 1] == 1 :
                continue
            if b[i] < a[i] and mn[i - 1] == -1 :
                continue
            if b[i] == a[i] :
                continue
            check = False 
        if check :
            print('YES')
        else :
            print('NO')