def g():
	n = int(input())
	res=0
	for i in range(n):
		#print(i)
		k = i
		j=2
		p = []
		while k!=1 and j<=(k**0.5):
			if k%j==0:
				k=k//j
				if j not in p:
					p.append(j)
				j=1
			j+=1
		if k not in p:
			p.append(k)
		#print(p)
		if len(p)==2:
			res+=1
	print(res)
g()