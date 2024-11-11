for i in range(int(input())):
	n,k=map(int,input().split())
	x=n%k
	if x==0 or n<k:
		print(n)
	else:	
		x=x-k//2
		print(n-x)