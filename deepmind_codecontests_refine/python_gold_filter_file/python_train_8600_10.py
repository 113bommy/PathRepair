q = int(input())
for i in range(q):
	n = int(input())
	y = n % 4
	if y == 0:
		print(n // 4)
	elif y == 1:
		n -= 9
		if n < 0:
			print(-1)
		else:
			print((n // 4) + 1)
	elif y == 2:
		n -= 6
		if n < 0:
			print(-1)
		else:
			print((n // 4) + 1)
	else:
		n -= 15
		if n < 0:
			print(-1)
		else:
			print((n // 4) + 2)	