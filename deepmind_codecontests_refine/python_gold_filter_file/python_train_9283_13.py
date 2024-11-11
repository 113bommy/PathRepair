n = int(input())
if n%2 == 0:
	print('NO')
else:
	print('YES')
	doubles = [[x, x+1] for x in range(1, 2*n, 2)]
	for i in range(n):
		print(doubles[i][i % 2], end = ' ')
	for i in range(n):
		print(doubles[i][(i+1)%2], end = ' ')
	print('')


