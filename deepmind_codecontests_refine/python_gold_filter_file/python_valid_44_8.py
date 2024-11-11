for i in range(int(input())):
    a,b=map(int,input().split())
    if a==b:
        if a==0:
            print(0)
        else:
            print(1)
    else:
        if abs(a-b)%2==1:
            print(-1)
        else:
            print(2)