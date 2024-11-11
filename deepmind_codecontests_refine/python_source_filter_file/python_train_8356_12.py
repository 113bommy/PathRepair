x=int(input())
for i in range(x):
	n=int(input())
	if n==4 or n<3:
		print(-1)
	else:
		a,b,c=0,0,0
		if n%3==0:
			a=n//3
		elif n%5==0:
			b=n//5
		elif n%7==0:
			c=n//7
		elif (n%5)%2==0:
			if n%5==4:
				b=n//5-1
				c=(n-5*b)//3
			else:
					b=n//5-1
					c=1
		elif n%5==1:
				b=n//5-1
				a=(n-5*b)//3
		elif n%5==3:
		       b=n//5
		       a=(n-5*b)//3
		print(a,b,c)
				
