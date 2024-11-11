#  Dreamoon and Stairs
n,m=map(int,input().split())
if n<m:
    print(-1)
else:
    q=n//m
    r=n%m
    c=q+r
    if c%m==0:
        print(c)
    else:
        i=1
        while q!=0 and c%m!=0:
            q-=i
            r+=i*m
            c=q+r
        if c%m==0:
            print(c)
        else:
            print(-1)
            