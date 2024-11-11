for i in range(int(input())):
	n = int(input())
	d = []
	cnt = 2
	c = 1
	a,b,c = 1,1,1
	for i in range(2,int(n**0.5)+1):
		if n%i==0:
			d.append(i)
	if len(d)<=2:
		print("NO")
	else:
		a = d[0]
		for j in range(len(d)):
			b = d[j]
			c = n//(a*b)
			if a*b*c==n and a<b<c:
				print("YES\n",a,b,c)
				c = 0
				break
	if c:
		print("NO")

