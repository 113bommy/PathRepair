for i in range(int(input())):
	arr=[int(x) for x in input().split()]
	n=arr[0]
	a=arr[1]
	b=arr[2]
	sum=0
	wat=0
	if a>b:
		sum+=b*int((n/2))
		wat+=int(n/2)*2
		if wat!=n:
			sum+=a*(n%2)
	else:
		sum+=a*n
	print(int(sum))
