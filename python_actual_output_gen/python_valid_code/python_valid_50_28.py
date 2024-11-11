for asda in range(int(input())):
	a,b,c=input().split()
	a=int(a)
	b=int(b)
	c=int(c)
	z=a*b
	if a>c:
		print(-1,b)
	elif z<c:
		print(1,-1)
	else:
		for ae in range(1,11):
			if z*ae>c*ae:
				p=b*ae
				break
			else:
				p=-1
		print(-1,p)