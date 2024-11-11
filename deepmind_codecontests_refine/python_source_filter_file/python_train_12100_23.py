for i in range(int(input())):
	m=list(map(int,input().split()))
	p=m[0]+m[1]
	q=m[2]+m[3]

	print(p//q if p%q==0 else -1)

