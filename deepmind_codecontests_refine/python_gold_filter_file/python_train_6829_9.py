n, k = map(int, input().split())

if n // 2 < k:
	print(0, 0, n)
else:
	print(n // 2 // (k + 1), n // 2 // (k + 1) * k, n - n // 2 // (k + 1) - n // 2 // (k + 1) * k)
