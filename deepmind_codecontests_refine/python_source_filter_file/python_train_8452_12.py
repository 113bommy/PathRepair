for i in range(int(input())):
	n, x, a, b = map(int, input().split())
	MaxMax = n - 1
	if (abs(b - a) + x)>n:
		print(n - 1)
	else:
		print(abs(b - a) + x)
