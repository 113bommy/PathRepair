n,x,y = [int(x) for x in input().split()]

z = y - (n-1)

if z <= 0 or z*z + (n-1) < x:
	print(-1)
else:
	print(z)
	for i in range(n-1):
		print(1)
