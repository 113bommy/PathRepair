for _ in range(int(input())):
	n = int(input())
	s = input()
	if n<11:
		print('NO')
	elif n==11 and s[0] != '8':
		print('NO')
	elif n>11 and ('8' not in s[:n-11]):
		print('NO')
	else:
		print('YES')