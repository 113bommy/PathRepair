[n,k]=[int(_) for _ in input().split()]
[l,r]=[0,n]
while(l+1<r):
    m=(l+r)//2
    p=m+m*k
    if (p<=n//2):
        l=m
    else:
        r=m
print(l,l*k,n-l*k-l)