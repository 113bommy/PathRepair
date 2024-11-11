t = int(input())
for q in range(t):
	n = int(input())
	mas = list(map(int, input().split()))
	d = 0
	maxi = mas[0]
	for i in range(1, n):
		d = max(d, maxi - mas[i])
		maxi = max(maxi, mas[i])
	if d == 0:
		print(0)
	else:
		now = 1
		kol = 1
		while now < d:
			now *= 2
			kol += 1
		print(kol)
