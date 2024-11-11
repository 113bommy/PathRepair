N,*E=map(int,open(0).read().split())
E=sorted((e,2*(i<N)-1)for i,e in enumerate(E))
a,c=1,0
for _,d in E:
	if c*d<0:a=(a*abs(c))%(10**9+7);c+=d
print(a)