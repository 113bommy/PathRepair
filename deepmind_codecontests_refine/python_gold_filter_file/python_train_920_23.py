N,x=map(int,input().split())
a=list(map(int,input().split()))
c=[[None]*N for i in range(N)]
for j in range(N):
    for i in range(N):
        if j==0:
            c[j][i]=a[i]
        else:
            c[j][i]=min(c[j-1][i-1],a[i])
ans=2*10**12
for i in range(N):
    ans=min(ans,sum(c[i])+x*i)
print(ans)