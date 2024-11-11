n,*a=map(int,open(0))
d={}
for i in a[:n]:d[i]=-1
for i in a[n:]:d[i]=1
a,c=1,0
for i in sorted(d):
  if((c>0)!=d[i])*c:a=a*abs(c)%(10**9+7)
  c+=d[i]
print(a)