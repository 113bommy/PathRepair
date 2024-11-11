n,*a=map(int,open(0).read().split())
d=[0]*-~n
for h,a in zip(a,a[n:]):
 i,s=h,0
 while i:s=max(s,d[i]);i-=i&-i
 while h<=n:d[h]=max(d[h],s+a);h+=h&-h
print(max(d))