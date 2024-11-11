a, b = map(int, input().strip().split())
t = 0


if a + b == 2:
	print(0)
else:
	while a > 0 and b > 0:
		if a <= b:
			a += 1
			b -= 2
		else:
			b += 1
			a -= 2
	print(t)