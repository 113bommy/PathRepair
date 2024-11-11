n,a,b=map(int,input().split())
l,r=1,min(a,b)
while l+1<r:
    mid=(l+r)//2
    res=a//mid+b//mid
    if res>n:l=mid
    else:r=mid
if a//r+b//r>=n:print(r)
else:print(l)