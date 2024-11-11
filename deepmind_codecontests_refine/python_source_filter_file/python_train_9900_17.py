n,k=map(int,input().split())
if k==1 or k>n*2-1:
	print(0)
else:
	t=k//2
	m=n//2
	if t>=m:
		print(n-t)
	else:
		if k%2==0:
			print(t-1)
		else:
			print(t)