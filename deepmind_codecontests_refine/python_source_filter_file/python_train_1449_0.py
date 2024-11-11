while True:
    N=int(input())
    if N==0:break
    t=[0]
    y=[0]
    lst=list(range(N))
    for k in lst[1:]:
        [x,d]=input().split()
        [x,d]=[int(x),int(d)]
        if d==0:
            t=t+[t[x]]
            y=y+[y[x]-1]
        if d==1:
            t=t+[t[x]-1]
            y=y+[y[x]]
        if d==2:
            t=t+[t[x]]
            y=y+[y[x]+1]
        if d==3:
            t=t+[t[x]+1]
            y=y+[y[x]]
    ht=0
    lt=0
    hy=0
    ly=0
    for f in range(N):
        if ht<t[f]:
            ht+=1
        if lt>t[f]:
            lt-=1
        if hy<y[f]:
            hy+=1
        if ly>y[f]:
            ly-=1
    print(ht-lt+1,hy-ly+1)