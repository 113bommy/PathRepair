n,p,k=map(int,input().split())
a=list(map(int,input().split()))
d=[0]*p
for i in range(n):
    e=(a[i]*a[i]*a[i]-k)*a[i]%p
    if e in d:
        d[e]+=1
    else:
        d[e]=1
ans=0
for i in d:
    ans+=d[i]*(d[i]-1)//2
print(ans)