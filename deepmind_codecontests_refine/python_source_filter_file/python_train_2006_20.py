for t in range(int(input())):
	a,b= map(int,input().split())

	if b>=a:
		print(b-a)
	else:
		if b==0:
			print(a%2)
		else:
			print(a-a%(2*b))

