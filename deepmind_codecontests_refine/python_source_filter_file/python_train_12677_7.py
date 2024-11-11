n,m,k=map(int,input().split())
a=[0]+list(map(int,input().split()))
b=[0]+list(map(int,input().split()))

for i in range(1,n+1): a[i]=a[i]+a[i-1]
for i in range(1,m+1): b[i]=b[i]+b[i-1]
j=m-1
ans=0
for i in range(n):
    if j<0: break
    while a[i]+b[j]>k and j>=0: j-=1
    ans=max(i+j,ans)
print(ans)