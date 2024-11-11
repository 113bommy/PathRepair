t=int(input())
for z in range(t):
	n,k=[int(x) for x in input().split()]
	s=input()
	a=[]
	for i in s:
		if i=="R":
			a.append(0)
		elif i=="G":
			a.append(1)
		else:
			a.append(2)
	flag=0
	ans=10000000
	# print(a)
	for i in range(n-k+1):
		q=a[i:i+k]
		# print(q)
		l=1000000
		
		for x in range(3):
			p=""
			d=0
			for y in range(x,x+k):
				p+=(str((y)%3))
			for j in range(k):
				if q[j]!=p[j]:
					# print(q[j],p[j])
					d+=1
			# print(p,q,d)
			l=min(l,d)

		ans=min(ans,l)		
	print(ans)







	


