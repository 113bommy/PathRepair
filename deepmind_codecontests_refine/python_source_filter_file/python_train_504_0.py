while True:
	n=int(input())
	if n==0: break
	l=[]
	d={}
	for i in range(n):
		i,p,q=list(map(int,input().split()))
		if a in d:
			d[a]+=b*c
		else:
			d[a]=b*c
			l.append(a)
	if max(d.values())<1000000:
		print("NA")
	else:
		for k in l:
			if d[k]>=1000000:
				print(k)