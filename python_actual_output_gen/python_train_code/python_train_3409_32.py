n,k=map(int,input().split())

if k<=n:
	print( (k)//2 )
elif n > k//2:
	print( n - k//2 )
else:
	print(0)
