t = int(input())
cnt = 0 
while (cnt < t):
    cnt += 1
    flag = False
    n = int(input())
    a = [int(i) for i in input().split()]
    a = sorted(a)
    for i in range(1, n):
        if a[i] == a[i - 1]:
            flag = True
            break
    d = {0 : 0, 1 : 0}
    for i in a:
        d[i % 2] = d.get(i % 2, 0) + 1
    if d[0] % 2 == 0 and d[1] % 2 == 0:
        print('YES')
    else:
        if flag == True:
            print('YES')
        else:
            print('NO')
    
    