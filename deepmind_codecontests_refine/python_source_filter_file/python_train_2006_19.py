for _ in range(int(input())):
    n,k = map(int,input().split())
    if k==0:
        if n%2==0:
            print(0)
        else:
            print(n)
    else:
        print(abs(n-k))