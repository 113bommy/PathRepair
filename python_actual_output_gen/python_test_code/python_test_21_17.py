n = int(input())
c = n // 2
if n % 2 == 0:
	print(2 ** (n - 1))
	for i in range(n):
		if i % 2 == 0:
			print('C.' * c)
		else:
			print('.C' * c)
else:
	print((n * (n // 2)) + (n // 2) + 1)
	for i in range(n):
		if i % 2 == 0:
			s = 'C.' * c
			print(s + 'C')
		else:
			s = '.C' * c
			print(s + '.')