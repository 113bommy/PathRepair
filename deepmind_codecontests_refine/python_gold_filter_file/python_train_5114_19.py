n=int(input().strip())
a=list(map(int, input().strip().split(' ')))
d=[False]*n

if 3<n:
    for i in range(1,n-1):
        if a[i]==0 and a[i-1]==1 and a[i+1]==1:
            d[i]=True
else:
    if a[1]==0 and a[0]==1 and a[2]==1:
            d[1]=True
#print(d)
ans=0
for i in range(n):
    if d[i]:
        ans+=1
        if i+2<=n-1 and d[i+2]:
            d[i+2]=False
print(ans)