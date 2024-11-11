n,k=map(int,input().split())
a=[list(map(int,input().split()))for i in range(n)]
l,r=2*(10**18)+1,0
while l-r>1:
    t=(l+r)//2
    c=0
    for i,j in a:
        c+=max(0,(t-i)//j+1)
    if c<k:
        r=t
    else:
        l=t
print(l)