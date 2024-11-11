n,k = map(int,input().split())

if (n*n+1)//2 < k:
    print('NO')
else:
    print('YES')

    for i in range(n):
        for j in range(n):
            if k>0 and (i+j)%2==0:
                print('L',end='')
                k -= 1
            else:
                print('S',end='')
        print()



