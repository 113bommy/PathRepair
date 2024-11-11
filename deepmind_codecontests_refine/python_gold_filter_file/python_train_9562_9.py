n,t=map(int,input().split())
a=list(map(int,input().split()))
ans=t
for i in range(n-1):
    ans+=min(a[i+1]-a[i],t)
print(ans)