from sys import stdin
input = stdin.buffer.readline

n, m, x, y = map(int, input().split())
print(x, y)
print(1, y)
i = j = c = 1
while i <= n:
	if c:
		while j <= n:
			if (i, j) not in [(x, y), (1, y)]:
				print(i, j)
			j += 1
		j -= 1
	else:
		while j >= 1:
			if (i, j) not in [(x, y), (1, y)]:
				print(i, j)
			j -= 1
		j += 1
	i += 1
	c ^= 1
