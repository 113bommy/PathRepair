n,m=map(int,input().split())
l=list(map(int,input().split()))
r=sum(l)
j=1
z=0
s=r
if r//n==m:
	print(j)
else:
	while(j>0):
		s+=(m)
		p=s/(j+n)
		z=int(p)
		if z+0.5<=p:
			if z+1==m:
				print(j)
				break
		j+=1