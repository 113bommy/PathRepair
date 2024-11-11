for t in range(int(input())):
    a,b,c,d=map(int,input().split())
    if a>b and d>=c:
        print(-1)
    else:
        if b>=a:
            print(b)
        else:
            if (a-b)%(c-d)==0:
                x=(a-b)//(c-d)
            else:
                x=(a-b)//(c-d)+1
            print(b+x*c)