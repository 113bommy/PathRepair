n,*a=map(int,open(0).read().split())
ma=a[0]
ans=0
for q in a:
  if ma>q:
    ans+=(ma-q)
  ma=max(ma,q)
print(ans)
