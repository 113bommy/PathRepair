for _ in range(int(input())):
	st=input()
	se=set()
	i=1
	if len(st)>1:
		while(i<len(st)):
			if st[i]==st[i-1]:
				i+=1
			else:
				se.add(st[i-1])
			i+=1
		c=st[-1]
		co=0
		for j in range(len(st)-1,-1,-1):
			if c==st[j]:
				co+=1
			else:
				break
		if co%2==1:
			se.add(c)
	else:
		se.add(st[0])
	print("".join(se))