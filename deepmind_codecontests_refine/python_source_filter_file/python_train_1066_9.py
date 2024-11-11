t=int(input())
for i in range(t):
    n,x,m=input().split()
    n=int(n)
    x=int(x)
    m=int(m)
    r,l=x,x
    for i in range(m):
        L,R=input().split()
        L=int(L)
        R=int(R)
        if min(l,L)<=min(r,R):
            l=min(l,L)
            r=max(r,R)
    print(r-l+1)

