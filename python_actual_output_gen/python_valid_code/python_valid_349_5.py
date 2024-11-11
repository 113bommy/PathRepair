t = int(input())
for _ in range(t):
	n, x, y, d = map(int, input().split())
	xmy = abs(x - y)
	xpy = x + y
	if xmy % d == 0:
		print(xmy // d)
	elif y % d == 1:
		if n % d == 1:
			print(min((xpy + d - 3) // d, (n * 2 - xpy) // d))
		else:
			print((xpy + d - 3) // d)
	elif (n - y) % d == 0:
		print((n * 2 + d - 1 - xpy) // d)
	else:
		print('-1')
