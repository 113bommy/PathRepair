
n = int(input())

n = 10 ** (n - 1)

while n % 21 != 0:
	n += 10

if n > 2:
	print(n)
else:
	print(-1)
