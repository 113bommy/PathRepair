for _ in range(int(input())):
	n,k,l=map(int,input().split())
	inp=list(map(int,input().split()))
	inp=[l-x for x in inp]
	a=[]
	cur=[]
	ans='Yes' if min(inp)>=0 else 'No'
	for x in inp:
		if x>=k:
			if len(cur)>1:
				a.append(cur)
				cur=[]
		else:
			cur.append(x)
	a.append(cur)
	for ls in a:
		td=k
		dsc=True
		for x in ls:
			if dsc:
				td=min(td-1,x)
				if td==0:dsc=False
			else:
				td+=1
				if x<td:ans='No'
	print(ans)