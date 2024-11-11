n=int(input())
for x in range(n):
	z=True
	a,b=map(int,input().strip().split())
	c,d=map(int,input().strip().split())
	p={a,b}
	q={c,d}
	try:
		k=p.intersection(q)
		k=list(k)
		k=k[0]
	except:
		z=False
	if z==True:
		p.remove(k)
		q.remove(k)
		if sum(p)+sum(q)==k:
			print('Yes')
		else:
			print('No')
	else:
		print('No')