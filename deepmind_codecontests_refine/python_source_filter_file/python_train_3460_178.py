for _ in range(int(input())):
	a, b, c, d = map(int, input().split())
	x = 0
	y = 0
	z = 0
	if a == 1 and b != 1:
		x = a+1
		y = c
		z = c+1
	elif a == 1 and b == 1:
		x = 1
		y = c
		z = c
	else:
		x = a
		y = c
		z = c+1
	print(x, end = " ")
	print(y, end = " ")
	print(z)
