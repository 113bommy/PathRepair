n, k = map(int, input().split())
a = [int(x) for x in input().split()]
mx = 0
for i in range(min(n, k)):
	for j in range(min(k - i + 1, n - i + 1)):
		summa = 0
		b = []
		for t in range(i):
			b.append(a[t])
		for t in range(n - j, n):
			b.append(a[t])
		z = k - i - j
		b.sort()
		for x in b:
			if x < 0 and z > 0:
				z -= 1
			else:
				summa += x
		mx = max(mx, summa)
print(mx)
