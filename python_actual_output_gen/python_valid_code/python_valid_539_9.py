for _ in range(int(input())):
    a,b,c=map(int,input().split())
    g=abs(b-a)
    n=2*g
    if(a>n or b>n or c>n):
        print(-1)
    else:
        d=(c+g)%(n+1)
        if(d==0):
            d=1
        print(d)
    
