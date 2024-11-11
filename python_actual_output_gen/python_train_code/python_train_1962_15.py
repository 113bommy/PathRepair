for _ in range(int(input())):
    n,m=map(int,input().split())
    b=n*m//2+1
    w=n*m-b
    f=1
    for i in range(n):
        for j in range(m):
            if f==1:
                print('W',end='')
                f=0
            else:
                print('B',end='')
    print()