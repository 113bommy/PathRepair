a,b,c = map(int,input().split())
if c == 0:
	print(1)
if c < 0:
	c = (-c)%a
	c = -c
	if b + c < 0:
		print(a+c+b)
	else:
		print(b+c)
if c > 0:
	c = (c)%a
	if b + c > a:
		print(c-a+b)
	else:
		print(b+c)