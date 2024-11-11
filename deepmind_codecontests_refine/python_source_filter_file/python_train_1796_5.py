for _ in range(int(input())):
    n,k = list(map(int,input().split()))

    if n % 2 == 0 and k % 2 == 1 or n < k :
        print('no')

    elif n % 2 == 0 and k % 2 == 1 :
        if k * 2 > n :
            print('no')

        else :
            print('yes')
            print(*list(2 for i in range(k-1)),n-(k-1)*2)

    elif n % 2 == 1 and k % 2 == 1 :
        print('yes')
        print(*list(1 for i in range(k-1)), n-(k-1))

    else :
        print('yes')
        print(*list(1 for i in range(k - 1)), n - (k - 1))
