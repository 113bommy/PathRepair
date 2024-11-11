n,m=map(int,input().split())
c=list(map(int,input().split()))
a=list(map(int,input().split()))
i,j,ans=0,0,0
while True:
    if i==n or j==m: break
    if c[i]<=a[j]:
        ans+=1
        i+=1
        j+=1
    else:
        j+=1
print(ans)
