n=int(input())
if(n<3):
	print(n)
	exit(0)
if n%2==1:
	print(n*(n-1)*(n-2))
else:
	g=0;
	if n%3==0:
		g=n-2
	else:g=n;
	print((n-1)*(n-2)*(g))
