for _ in range(int(input())):
	n,m=map(int,input().split())
	if n==1:
		print('0')
	elif n==2:
		print('1')
	else:
		print(2*m)