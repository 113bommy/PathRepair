for _ in range(int(input())):
    a=int(input())
    b=list(map(int,input().split()))
    if a==1:
        if b[0]%2==0:
            print(1)
            print(1)
        else:
            print(-1)
    else:
        if b[0]%2==1 and b[0]%2==1:
            print(2)
            print(1,2)
        elif b[0]%2==0:
            print(1)
            print(1)
        else:
            print(1)
            print(2)