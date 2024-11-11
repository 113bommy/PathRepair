for ii in range(int(input())):
	a,b,n,m = map(int,input().split())
	if m+n>a+b :
		print('No')
	else :
		x = min(a,b)
		y = max(a,b)
		if x<m :
			print('No')
		else :
			x -= b
			if (x+y)>=n :
				print('Yes')
			else:
				print('No')



