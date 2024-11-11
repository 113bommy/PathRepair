n,k=map(int,input().split())

if k<=n:
	print( (k-1)//2 )
elif n > (k-1)//2:
	print( n - (k-1)//2 )
else:
	print(0)
