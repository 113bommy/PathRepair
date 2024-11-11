def doit(m, c):
	i = 0
	while i < len(c):
		p = c.pop(i)
		if p in c:
			i -= 1
			j = c.index(p)
			c.append(2 * c[j])
			c.pop(j)
			print(*c)
		else:
			c.insert(i, p)
			i += 1
		if 2048 in c:
			break

n = int(input())
for i in range(n):
	m = int(input())
	c = list(map(int, input().split()))
	if 2048 not in c:
		doit(m, c)
	if 2048 in c:
		print('YES')
	else:
		print('NO')
