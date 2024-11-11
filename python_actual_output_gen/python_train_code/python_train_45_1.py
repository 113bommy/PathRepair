for i in range(int(input())):
	a,b,c=map(int,input().split())
	r=0
	p=min(b,c//2)
	r+=p*3
	b=b-p
	if b<=0:
		print(0)
	else:
		q=min(a,b//2)
		r+=q*3
		print(r)