r = int(input())
if r < 3:
	print('NO')
elif r % 2:
	print(1, (r - 3) // 2)
else:
	print('NO')