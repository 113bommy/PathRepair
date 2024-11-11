t = int(input())

for _ in range(t):
	n, x = map(int, input().split())
	s = input()
	tab = [0]
	a, b = 0, 0
	for i in range(n):
		if s[i] == '0':
			a += 1
		else:
			b += 1
		tab.append(a-b)
	diff = a - b
	count = 0
	if diff != 0:
		if x == 0:
			count += 1
		for i in range(1, n + 1):
			if tab[i] < x and diff > 0:
				if tab[i] % diff == x % diff:
					count += 1
			elif tab[i] > x and diff < 0:
				if tab[i] % diff == x % diff:
					count += 1
			elif tab[i] == x:
				count += 1
	else:
		for i in range(n + 1):
			if tab[i] == x:
				count = -1
	print(count)