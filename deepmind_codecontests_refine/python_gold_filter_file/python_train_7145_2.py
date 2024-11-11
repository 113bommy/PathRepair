n,l=map(int,input().split())
a=list(map(int,input().split()))
for i in range(0,n-1):
    a[i+1]=min(a[i+1],2*a[i])
s=0
ans=100**100
for i in range(n-1,-1,-1):
    d=l//(1<<i)
    s+=d*a[i]
    l-=d<<i;
    ans=min(ans,s+(l>0)*a[i])
print(ans)
