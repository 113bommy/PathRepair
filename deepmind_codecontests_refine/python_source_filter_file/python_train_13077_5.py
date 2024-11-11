a, b = map(int, input().split())

if b - a > 10:
	print(0)
else:
	c = a
	for x in range(a + 1, b + 1):
		c *= x % 10
		c = c % 10
	print(c)
