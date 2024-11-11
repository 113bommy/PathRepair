n = int(input())
for _ in range(n):
	a = []
	p = int(input())
	if p == 1:
		a.append(2)
	elif p % 2 == 0:
		for k in range(p):
			a.append(2)
	else:
		for k in range(p):
			a.append(1)
	print(a)
