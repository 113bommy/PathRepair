n,k=map(int,input().split())
a=list(map(int,input().split()))
a.sort(reverse=True)
b=[a[0]]
for i in range(1,n):
    b.append(b[-1]+a[i])
ans=-1
s=0
j=-1
for i in range(n):
    s+=a[i];
    l=i;
    r=n;
    while r>l+1:
        m=(l+r)//2
        if a[i]*(m-i)-(b[m]-s)<=k:
            l=m
        else:
            r=m
    if  l-i+1>=ans:
        ans=l-i+1
        j=a[i]
print(ans,j)


