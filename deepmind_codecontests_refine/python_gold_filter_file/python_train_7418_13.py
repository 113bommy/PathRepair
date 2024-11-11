for _ in range(int(input())):
	n = int(input())
	if n < 31:
		print('NO')
	else:
		print('YES')
		if n-30 in [6,10,14]: 
			print(n-31,6,10,15)
		else:
			print(n-30,6,10,14)