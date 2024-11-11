n,k,m,t = list(map(int,input().split()))
for i in range(t):
    q = list(map(int,input().split()))
    if q[0] == 0:
        ind = q[1]
        if k >= ind:
            k -= ind
            n -= ind
        else:
            n -= (n-ind)

    else:
        ind = q[1]
        if k >= ind:
            k += 1
        n += 1
    print(n, k)