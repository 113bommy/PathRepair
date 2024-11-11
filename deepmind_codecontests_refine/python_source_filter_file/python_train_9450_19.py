n,k,*a=map(int,open(0).read().split())
v=[0]+[-1]*~-n
p=0
for i in range(n):
  t=a[p]-1
  if v[t]>=0: l,r=v[t],i+1; break
  v[t]=i+1; p=t
print([k,v.index(l+(k-l)%(r-l))][k>l]+1)