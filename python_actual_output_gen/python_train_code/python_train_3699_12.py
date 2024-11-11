n,m=map(int,input().split())
if n<m:
    print(n)
else:
    (l, r) = (0, int(10**18))
    n-=m
    while l<r:
        mid=(l+r)//2
        val=mid*(mid+1)
        print(val)
        if val>=2*n:
            r=mid
        else:
            l=mid+1
    print(m+l)
