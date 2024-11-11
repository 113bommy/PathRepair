n,m=map(int,input().split())
a=list(map(int,input().split()))
for i in range(m):
    if(a[i]+i>n):
        print(-1)
        exit(0)
pre=[0 for i in range(m+1)]
for i in range(m-1,-1,-1):
    pre[i]=pre[i+1]+a[i]
if(pre[0]<n):
    print(-1)
    exit(0)
for i in range(m):
    print(max(i+1,n-pre[i]+1),end=" ")
print()
