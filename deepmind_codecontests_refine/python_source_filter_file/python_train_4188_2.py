n = int(input())
 
for _ in range(n):
    m = int(input())
    a = [0] + [int(x) for x in input().split(' ')]
 
    gbl_sum = 0
    lcl_sum = 0
    r, l, d = 0, 0, 0
    for i in range(m+1):
        lcl_sum += a[i]
 
        if lcl_sum <= 0:
            lcl_sum = 0
            r = i
 
        if gbl_sum < lcl_sum:
            gbl_sum = lcl_sum
            l = i
            d = max(d, l-r)
 
    print(gbl_sum, d)
    if (gbl_sum >= sum(a) and d < m):
        print('NO')
    else:
        print('YES')