for i in range(int(input())):
    n,x,y=list(map(int,input().split()))
    m=x+(y-x)*(n-1)
    q=y-x
    for d in range(1,int((y-x)**0.5)+1):
        if (y-x)%d==0:
            if (y-x)//d+1<=n:
                if y//d+min(1,y%d)>=n:
                    m,q=y,d
                    break
                elif (n-y//d-min(1,y%d))*d+y<m:
                    m,q=(n-y//d-min(1,y%d))*d+y,d
            d=(y-x)//d
            if (y-x)//d+1<=n:
                if y//d+min(1,y%d)>=n:
                    m,q=y,d
                    break
                elif (n-y//d-min(1,y%d))*d+y<m:
                    m,q=(n-y//d-min(1,y%d))*d+y,d
    print(*list(range(m-q*(n-1),m+1,q)))