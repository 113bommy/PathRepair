n = int(input())
for _ in range(n):
	length = int(input())
	number = input()
	if '8' in number and length - number.find('8') > 10:
		print('YES')
	else:
		print('NO')