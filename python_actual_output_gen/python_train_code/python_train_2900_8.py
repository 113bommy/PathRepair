for _ in range(int(input())):
    n,x,a,b=map(int,input().split())
    if a-b==n-1:
        print(abs(a-b))
    elif x==0:
        print(abs(a-b))
    else:
        t=max(a,b)
        p=min(a,b)
        if t+x<=n:
            print(t+x-p)
        else:
            r=t+x-n
            if p>0:
                s=p-r
                if s>=0:
                    print(n-s)
                else:
                    print(n-1)
