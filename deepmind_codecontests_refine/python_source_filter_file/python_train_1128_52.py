def resolve():
	n = input()
	c = [False] * 8
	p = 0
	for i in list(map(int, input().split())):
		if i >= 3200:
			p += 1
		else:
			c[i//400] = True
	print(sum(c), sum(c) + p)
resolve()