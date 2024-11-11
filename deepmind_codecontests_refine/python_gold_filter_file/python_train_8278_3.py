def f(c,k,a,b):
    u=0
    for i in range(len(a)):
        r=a[i]*c
        if r>b[i]:
            u+=(r-b[i])
    if u<=k:
        return True
    else:
        return False

n,k=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))

mi,ma=10**18,0
for i in range(len(a)):
    mi,ma=min(mi,b[i]//a[i]),max(ma,b[i]//a[i])

low,high,ans=0,10**18,0
while(low<=high):
    mid=low+(high-low)//2
    x=f(mid,k,a,b)
    if x:
        ans=max(ans,mid)
        low=mid+1
    else:
        high=mid-1
print(ans)