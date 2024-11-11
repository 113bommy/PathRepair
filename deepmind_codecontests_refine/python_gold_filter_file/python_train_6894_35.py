for _ in range(int(input())):
    n,k=map(int,input().split())
    if n%k==0:
        print('Yes')
    else:
        print('NO')