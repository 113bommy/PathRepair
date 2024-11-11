n,m,k,x,y=[int(x) for x in input().split()]
ma=0
mi=0
minn=199999999999999999
maxx=-1
if n is 1:
    mi=k//m
    ma=mi
    k=k%m
    a=[0]*m
    for p in range (m):
        if k is 0:
            break
        a[p]=1
        k-=1
    for p in range(m):
        if a[p]>maxx:
            maxx=a[p]
        if a[p]<minn:
            minn=a[p]
    print(ma+maxx,mi+minn,mi+a[y-1])
else:
    i=(2*n-2)*m
    mi=k//i
    if n>2:
        ma=mi*2
    else:
        ma=mi
    k=k%i
    a = [[0 for p in range(m)] for q in range(n)]
    for p in range(n):
        for q in range(m):
            if p is 0 or p is n-1:
                a[p][q]=mi
            else:
                a[p][q]=ma
    for p in range(n):
        if k is 0:
            break
        for q in range(m):
            if k is 0:
                break
            a[p][q]+=1
            k-=1
    for p in range(n):
        if k is 0:
            break
        for q in range(m):
            if k is 0:
                break
            a[n-2-p][q]+=1
            k-=1
    for p in range(n):
        for q in range(m):
            if a[p][q]>maxx:
                maxx=a[p][q]
            if a[p][q]<minn:
                minn=a[p][q]
    if x is 1 or x is n:
        print(maxx,minn,a[x-1][y-1])
    else:
        print(maxx,minn,a[x-1][y-1])
