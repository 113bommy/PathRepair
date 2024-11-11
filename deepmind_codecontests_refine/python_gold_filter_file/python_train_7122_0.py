n,m=map(int,input().split())
A=[0]*(n+1)
ans=0
for _ in range(m):
    a,b,c=map(int,input().split())
    A[a]+=c
    A[b]-=c
for i in range(n+1):
    if A[i]>=0:
        ans+=A[i]
print(ans)
