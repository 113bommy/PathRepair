def tim(c,m,x):
    s=c+m+x
    kq=0
    if(s<3):
        return 0
    if(s==3):
        if(c==0 or m==0):
            return 0
        else:
            return 1
    if(c==0 or m==0):
        return 0
    mn=min(c,m,s//3)
    c=c-mn
    m=m-mn
    t=c+m+x
    if(t>=mn):
        kq=mn
    else:
        kq=t
    return kq
q=int(input())
for i in range(q):
    a,b,c=map(int,input().split())
    kq=tim(a,b,c)
    print(kq)