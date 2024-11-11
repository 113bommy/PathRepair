for _ in range(int(input())):
	a, b = map(int, input().split())
	k = 0
	while b > 0:
		k += 1
		b //= 10
	print( a * (k-1) )