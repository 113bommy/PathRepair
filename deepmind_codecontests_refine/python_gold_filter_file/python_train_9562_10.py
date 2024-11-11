ans=0
n,k=map(int,input().split())
a=list(map(int,input().split()))
for i in range(1,n):
  ans+=min(a[i]-a[i-1],k)
ans+=k
print(ans)