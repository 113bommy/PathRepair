n, ans=int(input()), 0
ap, bp=0, 0
for i in range(n):
	a,b=(int(j) for j in input().split())
	mins=min(a, b)
	maxs=max(ap, bp)
	if(mins>=maxs):
		ans+=mins-maxs+1
	if(a==b):
		ans-=1
	ap, bp=a, b
print(ans+1)