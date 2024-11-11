n,k=list(map(int,input().split()))
p=list(map(int,input().split()))
ans=0
for i in range(n):
    if p[i]>=2*k:
        ans=ans+p[i]//(2*k)
        p[i]=p[i]%(2*k)
for i in range(n):
    if p[i]>=k:
        ans=ans+1
        p[i]=p[i]%k
e=0
for i in range(n):
    if p[i]>0:
        e=e+1
ans=ans+e//2+e%2
print(ans)