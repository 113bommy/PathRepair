n = int(input().strip())

c = 0

for i in range(0, n):
	a, b, c = map(int, input().strip().split(' '))

	if (a + b + c) >= 2:
		c += 1

print(c)