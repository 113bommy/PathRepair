def I(): return(list(map(int,input().split())))
n,l,r,x=I()
c=I()
l1=list(range(2**n))
ans=0
for j in l1:
	s=0
	num=0
	ma=0
	mi=100000
	for i in range(n):
		if (j & 1<<i):
			num+=1
			s+=c[i]
			ma=max(c[i],ma)
			mi=min(c[i],mi)

	if s<=r and l<=s and(ma-mi>=x) and num>=2 :
		ans+=1
print(ans)


