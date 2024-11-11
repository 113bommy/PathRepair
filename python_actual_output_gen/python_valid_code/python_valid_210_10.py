
n = int(input())
l = []
d = 1
pos = 1
while len(l) < n - 1:
	pos += d

	mul = pos // n
	if pos % n == 0:
		l.append(pos)
	else:
		

		l.append(pos - mul * n)

	d += 1

print(*l, sep = ' ')
