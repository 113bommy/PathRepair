if __name__ == '__main__':
	a = input().split()
	n = int(a[0])
	m = int(a[1])
	if n // m < 1:
		print(-1)
	else:
		optAmount = n // m + n % m
		while not optAmount % m == 0:
			optAmount += 1
		if optAmount > n:
			print(-1)
		else:
			print(optAmount)