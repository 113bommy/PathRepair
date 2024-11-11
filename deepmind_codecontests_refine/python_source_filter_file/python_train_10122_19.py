for _ in range(int(input())):
    n,m=map(int,input().split())
    if n==m:
        print(0)
    elif n<m:
        a=m-n
        if a%2==0:
            print(1)
        else:
            print(2)
    elif n>m:
        a=n-m
        if a%2==0:
            print(1)
        else:
            print(2)
