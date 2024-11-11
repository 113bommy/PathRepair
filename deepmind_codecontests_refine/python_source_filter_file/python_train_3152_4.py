for _ in range(int(input())):
    a,b,x,y,n = map(int,input().split())
    # if a>b:
    #     if a-x<b-y:
    #         a,b = b,a
    #         x,y = y,x
    # elif a==b:
    #     if a-x<b-y:
    #         a,b = b,a
    #         x,y = y,x
    if a>b or a-min(n,a-x)>b-min(n,b-y):
        a,b = b,a
        x,y = y,x
    a,n = a-min(n,a-x), n-min(n,a-x)
    b-=min(n,b-y)
    print(a*b)