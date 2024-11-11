n,x=map(int,input().split())
a=[int(i) for i in input().split()]

ans=0
for i in range(n-1):
    if a[i]+a[i+1]>x:
        ans+=a[i+1]-x+a[i]
        a[i+1]=max(0,x-a[i])
print(ans)