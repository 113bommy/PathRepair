for _ in range(int(input())):
    a,b,c=map(int,input().split())
    g=abs(b-a)
    n=2*g
    if(a>n or b>n or c>n):
        print(-1)
    else:
        d=int((c+g)%n)
        if(d==0):
            d=n
        print(d)
    
