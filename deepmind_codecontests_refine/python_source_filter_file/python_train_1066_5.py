for _ in range(int(input())):
	a,b,c = map(int,input().split())
	z,x,v=b,b,1
	for _ in range(c):
		q,w= map(int,input().split())
		if z>=q and x<=w:
			v+=(z-q)+(w-x)
			z,x=q,w
		elif z>=q and z<=w:
			v+=(w-q)
			z=q
		elif x>=q and x<=w:
			v+=(w-x)
			x=w
	print(v)