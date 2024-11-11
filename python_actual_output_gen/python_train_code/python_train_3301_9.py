ans=0
n,k=map(int,input().split())
a=list(map(int,input().split()))
for i in range(n):
  ans+=min(a[i],k)
ans+=k
print(ans)