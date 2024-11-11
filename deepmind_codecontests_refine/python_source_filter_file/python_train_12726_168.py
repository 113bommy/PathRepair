for _ in range(int(input())):
    n,b=map(int,input().split())
    if n<=3:
        if n==1:
            print(0)
        else:
            print(b)
    else:
        print((b)*2)
