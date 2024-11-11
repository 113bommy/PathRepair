for _ in range(int(input())):
	a,b=list(map(int,input().split()))
	if a==b:
		print((2*a)*(2*a))
		continue
	if a<b:
		a,b=b,a
	else:
		b=2*b
		print(max(a*a,b*b))