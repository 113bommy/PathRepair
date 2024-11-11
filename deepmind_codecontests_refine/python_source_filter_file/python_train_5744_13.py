def su(n):
	c=[0]*(n+1)
	while(n!=0):
		a=n%10
		n=n//10
		c.append(a)
	return sum(c)
n=int(input())
if su(n)%4==0:
	print(n)
else:
	for i in range(1,4):
		if su(n+i)%4==0:
			print(n+i)
			break