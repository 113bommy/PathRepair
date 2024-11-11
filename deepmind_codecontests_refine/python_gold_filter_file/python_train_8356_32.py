for _ in range(int(input())):
	n = int(input())
	flag = False
	for x in range(334):
		for y in range(201):
			if (n-3*x-5*y)%7==0 and (n-3*x-5*y) >=0:
				print(x,y,(n-3*x-5*y)//7)
				flag = True
				break
		if flag:
			break
	if not flag:
		print(-1)