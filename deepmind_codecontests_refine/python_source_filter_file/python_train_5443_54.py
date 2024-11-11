for _ in range(int(input())):
    l,r=map(int,input().split())
    if(r>=2*l-1):
        print('NO')
    else:
        print('YES')