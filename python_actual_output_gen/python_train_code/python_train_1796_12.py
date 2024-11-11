n,*a=map(int,open(0).read().split())
mod=10**9+7
l=[0]*n
l[0]=3
ans=1
for ai in a:
  ans*=l[ai]
  ans%=mod
  l[ai]-=1
  l[ai+1]+=1
print(ans)