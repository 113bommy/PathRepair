import math
n,k=map(int,input().split())
n-=1
k-=1
if n>(k*(k+1))//2:
    print(-1)
else:
    l=-1
    r=k+1
    while r>l+1:
        m=(l+r)//2
        if n>=(m*(2*k-m+1))//2:
            l=m
        else:
            r=m
    print(l)