t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    m=min(a)
    m1=min(b)
    c=0
    for i in range(1,n):
        if a[i]>m and b[i]>m1:
            v=a[i]-m
            v1=b[i]-m1
            v2=min(v,v1)
            c=c+v2
            a[i]=a[i]-v2
            b[i]=b[i]-v2
        if a[i]>m:
            v=a[i]-m
            a[i]=a[i]-v
            c=c+v
        if b[i]>m1:
            v=b[i]-m1
            a[i]=a[i]-v
            c=c+v
    print(c)