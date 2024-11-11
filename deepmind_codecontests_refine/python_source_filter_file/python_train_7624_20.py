t=int(input())
if 1<=t<=10000:
	for i in range(t):
		a,b=input().split()
		a=int(a)
		b=int(b)
		if 1<=a<=100 and 1<=b<=100:
			if a==b:
				m=4*a*b
				print(m)
			else:
				m=2*a*b
				n=m**(.5)
				if n%2==0 or (n-1)%2==0:
					n=int(n)
					if n>=a and n>=b:
						if n<(a+b) and n<2*a and n<2*b:
							if (a+b)<=2*a and (a+b)<=2*b:
								p=(a+b)**2
								print(p)
							elif 2*a<=(a+b) and 2*a<=2*b:
								p=(2*b)**2
								print(p)
							elif 2*b<=(a+b) and 2*b<=2*a:
								p=(2*b)**2
								print(p)
						else:
							print(m)
					else:
						if a>n and a>b:
							p=a**2
							p=int(p)
							print(p)
						elif b>n and b>a:
							p=b**2
							p=int(p)
							print(p)
				else:
					q=(n//1)+1
					q=int(q)
					if q>=a and q>=b:
						if q<(a+b) and q<2*a and q<2*b:
							if (a+b)<=2*a and (a+b)<=2*b:
								p=(a+b)**2
								print(p)
							elif 2*a<=(a+b) and 2*a<=2*b:
								p=(2*a)**2
								print(p)
							elif 2*b<=(a+b) and 2*b<=2*a:
								p=(2*b)**2
								print(p)
						else:
							p=q**2
							p=int(p)
							print(p)
					else:
						if a>q:
							p=a**2
							p=int(p)
							print(p)
						elif b>q:
							p=b**2
							p=int(p)
							print(p)
						