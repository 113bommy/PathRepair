n,*a=map(int,open(0).read().split())
ma=a[0]
ans=0
for q in a:
  if q>ma:
    ans+=(q-ma)
  ma=max(ma,q)
print(ans)
