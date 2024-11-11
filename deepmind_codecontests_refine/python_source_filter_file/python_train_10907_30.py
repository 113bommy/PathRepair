x,k,d=map(int,input().split())

if x>k*d:
	print(x-k*d)

else:
	k-=x//d
	x-=(x//d)*d
	rem=k%2
	if rem:
		print(d-x%d)
	else:
		print(x%d)
	