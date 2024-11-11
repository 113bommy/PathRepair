for _ in range(int(input())):
	n,m=map(int,input().split())
	for j in range(n):
		for i in range(m):
			if (i+j)%2==0:
				print('B',end='')
			else:
				print('W',end='')
		print('')
