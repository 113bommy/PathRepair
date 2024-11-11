for i in range(int(input())):
    a,b=map(int,input().split())
    r=0
    while a>0 or b>0:
        r+=b-a
        a//=10
        b//=10
    print(r)