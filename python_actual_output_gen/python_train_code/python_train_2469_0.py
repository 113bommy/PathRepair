n,l=map(int,input().split())
m=[0]+list(map(int,input().split()))
for i in range(2,n+1):
    m[i]=min(m[i],m[i-1]*2)
ans=10**18
z=1
k=0
while z<n:
    k+=(l//2**(n-z))*m[-z]
    l=l%2**(n-z)
    if l==0:
        ans=min(ans,k)
        break
    else:
        ans=min(ans,k+m[-z])
    z+=1
print(ans)