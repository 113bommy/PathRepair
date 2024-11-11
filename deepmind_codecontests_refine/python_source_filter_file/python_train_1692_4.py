t=int(input())
for _ in range(t):
	a,b=map(int,input().split())
	if b>a:
		count=0
		while 8*a<=b:
			a*=8
			count+=1
		while 4*a<=b:
			a*=4
			count+=1
		while 2*a<=b:
			a*=2
			count+=1
		if a==b:
			print(count)
		else:
			print(-1)
	if b<a:
		(a,b)=(b,a)
		count=0
		while 8*a<=b:
			a*=8
			count+=1
		while 4*a<=b:
			a*=4
			count+=1
		while 2*a<=b:
			a*=2
			count+=1
		if a==b:
			print(count)
		else:
			print(-1)
	else:
		print(0)
