for _ in range(int(input())):
    n,m,k = map(int,input().split())
    if max(n,m)>k:
        print(-1)
    else:
        if (n+m)%2==0:
            if k%2==0:
                print(k)
            else:
                print((k-2))
        else:
            print(k-1)
