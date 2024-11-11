for nt in range(int(input())):
	a=input()
	b=input()
	c=input()
	ans="YES"
	for i in range(len(a)):
		if len(set([a[0],b[0],c[0]]))>2:
			ans="NO"
			break
		if a[i]==b[i] and c[i]!=a[i]:
			ans="NO"
			break
	print (ans)