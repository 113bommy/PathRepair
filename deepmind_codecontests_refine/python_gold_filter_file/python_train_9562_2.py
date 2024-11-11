n,t=map(int,input().split())
a=list(map(int,input().split()))
ans=0
for i in range(n-1):
    ans+=min(a[i+1]-a[i],t)
ans+=t
print(ans)