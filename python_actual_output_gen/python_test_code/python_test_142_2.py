t = int(input())

while t > 0:
	a, b = map(int, input().split())

	if a == 0 and b == 0:
		print(1)

	elif a == 0:
		print(0.5)

	elif b == 0:
		print(0)

	else:
		ans = a * b + a * a / 8.0

		if 4 * b <= a:
			ans = 2.0 * b * b + (a - 4.0 * b) * b + a * b

		ans /= 2.0 * a * b
		print("%.10f" % ans)

	t -= 1