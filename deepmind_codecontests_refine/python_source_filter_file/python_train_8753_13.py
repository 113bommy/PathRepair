#   play with code

n ,k ,s = [int(x) for x in input().split()]

if k > s or k * (n - 1) < s :
    print('NO')
else :
    res = [1]*k
    rem1 = s%k
    inc = s//k

    for i in range(0,k,2):
        res[i] += inc

    for i in range(0,k,2):
        if rem1 < 2 :
            break
        res[i] += 1
        rem1 -= 2

    if rem1 :
        if k % 2 == 0 :
            dif = res[-2]-res[-1]
            if res[-2]+dif+1 <= n :
                res[-1] = res[-2]+dif+1
            else :
                res[0] += 1
                res[-1] += 1
        else :
            res[-1] += 1

    print('YES')
    print(*res)


