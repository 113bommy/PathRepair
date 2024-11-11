for _ in range(int(input())):
	n,x,y,d=[int(x) for x in input().split()]
	v1=0
	v2=0
	flag=0
	if (x-y)%d==0:
		flag=1
	elif (y-1)%d==0:
		if x%d==0:
			v1=((y-1)//d+(x//d))
		else:
			v1=((y-1)//d+(x//d)+1)
	elif (n-y)%d==0:
		if (n-x)%d==0:
			v2=((n-x)//d+(n-y)//d)
		else:
			v2=((n-x)//d+1+(n-y)//d)
	if flag==1:
		print(abs(x-y)//d)
	elif v1==v2==0:
		print(-1)
	elif v1==0:
		print(v2)
	elif v2==0:
		print(v1)
	else:
		print(min(v1,v2))
