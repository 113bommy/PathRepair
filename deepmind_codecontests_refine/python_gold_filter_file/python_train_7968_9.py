n = int(input())


if n == 1 or n == 2:
	print(-1)
elif n % 4 == 0:
	ans = [n/4*3, n/4*5]
	print(" ".join(map(lambda x: str(int(x)),ans)))
else:
	m = n 
	while m % 2 == 0:
		m = m // 2
	ans = [(m ** 2 - 1) // 2 * (n//m), (m ** 2 + 1) // 2 * (n//m)]
	print(" ".join(map(lambda x: str(int(x)),ans)))