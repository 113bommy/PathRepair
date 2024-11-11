def first():
    f,m,s,x=map(int,input().split())
    flg=0
    if x>=s:
        if 2*s>=x:
            c=x
            flg=1
    else:
        if 2*x>=s:
            c=s
            flg=1
    if x>=f or x>=m:
        flg=0
    if 2*x>=m:
        m=m+1
        if f<=m:
            f=f+1
    if flg==1:
        print(f);print(m);print(c)
    else:
        print(-1)
first()