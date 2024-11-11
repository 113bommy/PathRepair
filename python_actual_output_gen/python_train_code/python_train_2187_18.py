n,k=map(int,input().split())
a=list(map(int,input().split()))
ans,rev,sm=0,0,0
for i in range(1,n):
    for j in range(i):
        if a[i]<a[j]: rev+=1
        elif a[i]<a[j]: sm+=1
ans+=rev*k
ans+=(n*(n-1)//2-sm)*(k*(k-1)//2)
print(ans%(10**9+7))