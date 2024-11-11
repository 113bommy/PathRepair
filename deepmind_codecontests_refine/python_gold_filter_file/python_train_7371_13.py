N = int(input())

if N == 1 or N == 2:
	print(4)
else:
	m = 0
	while N > 1:
		if N % 2 == 0:
			N = N // 2
		else:
			N = 3 * N + 1
		m += 1
	print(m+2)

