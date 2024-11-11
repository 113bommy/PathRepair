t = int(input())

while t:
	a, b, c = map(int, input().split())

	if c < a:
		print(c)
	else:
		b += 1
		print(b + (c - (b % c)))

	t -= 1

