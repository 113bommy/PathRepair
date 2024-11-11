def fibonacci(n):
	a=[0,1]
	c=0
	i=1
	while(c<=n):
		c=a[i-1]+a[i]
		i+=1
		a.append(c)
	return(a)

n=int(input())
l=fibonacci(n)
for i in range(1,n+1):
	if i in l:
		print('0',end='')
	else:
		print('o',end='')