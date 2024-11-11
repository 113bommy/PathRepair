n,m = map(int,input().split())
if n<=m: print(n)
else:
    l,r = 0,int(2e9)
    while l<r:
        m = (l+r)//2
        val = m*(m+1)//2
        if n-val<=m: r=m
        else: l=m+1
    print(l+m)