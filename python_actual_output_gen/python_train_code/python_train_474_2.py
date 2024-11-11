n,x=map(int,input().split())
a=list(map(int,input().split()))
ans=0
for k in range(x,n):
  s=sum(a[:k])
  ans=max(ans,s/k)
  for i in range(k,n):
    s-=a[i-k]
    s+=a[i]
    ans=max(ans,s/k)
print(ans)