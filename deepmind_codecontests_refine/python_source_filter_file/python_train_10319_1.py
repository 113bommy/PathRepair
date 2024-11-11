def update(indx):
    sgn_tree[indx]=0
    indx=indx>>1
    while indx>=1:
        sgn_tree[indx]=sgn_tree[indx<<1]+sgn_tree[(indx<<1)+1]
        indx=indx>>1


def queries(l,r):
    add=0
    while l<=r:
        if l%2==1:
            add+=sgn_tree[l]
            l+=1
        if r%2==0:
            add+=sgn_tree[r]
            r-=1
        l=l>>1
        r=r>>1
    return add

n,cost=map(int,input().split())
a=list(map(int,input().split()))
sgn_tree=[0]*(2*n)
for i in range(n,2*n):
    sgn_tree[i]=a[i-n]
for i in range(n-1,0,-1):
    sgn_tree[i]=sgn_tree[i<<1]+sgn_tree[(i<<1)+1]
i=0
count=0
while i<n:
    if cost>=sgn_tree[1]:
        count+=(cost//sgn_tree[1])*(n-i)
        cost=cost%sgn_tree[1]
    l,r=n,2*n-1
    while l<r:
        m=(l+r)//2
        if queries(n,m)<=cost:
            l=m+1
        else:
            r=m-1
    if queries(n,l)<cost:
        update(l+1)
    else:
        update(l)
    i+=1
print(count)