for _ in range(int(input())):
	n,m=map(int,input().split())
	for j in range(n):
		for i in range(m):
			if (i+j)==0:
				print('W',end='')
			else:
				print('B',end='')
		print('')