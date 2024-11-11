for _ in range(int(input())):
	flag = 0
	y = 1
	a, b, c, d = [int(x) for x in input().split()]
	x = a - b
	if a > b and d >= c:
		flag = 1
	if a <= b:
		flag = 2
	if c - d != 0:
		if x//(c-d) == x/(c-d) and flag == 0:
			y = x//(c-d)
		elif x//(c-d) != x/(c-d) and flag == 0:
			y = x//(c-d) + 1
	z = b + c*y
	if flag == 0:
		print(z)
	if flag == 2:
		print(b)
	else:
		print(-1)