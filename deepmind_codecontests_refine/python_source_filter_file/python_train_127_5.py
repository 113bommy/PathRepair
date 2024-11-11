for c in range(0,int(input())):
    n,m = input().split(' ')
    n = int(n)
    m = int(m)
    a = input().split(' ')
    b = input().split(' ')
    d = -1
    f = 0
    while d < n-1:
        if f == 1:
            break
        e = -1
        d = d + 1
        a[d] = int(a[d])
        while e < m-1:
            e = e + 1
            b[e] = int(b[e])
            if a[d] == b[e]:
                print('YES')
                print(a[d])
                f=f+1
                break
    if f == 0:
        print('NO')
