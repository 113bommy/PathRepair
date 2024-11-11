a = int(input())

if a<3:
	print(-1)
else:
	if a%2==0:
		a //= 2
		b = (a**2-1)
		c = b + 2
	else:
		b = (a**2-1)/2
		c = b+1
	print("{} {}".format(b,c))
