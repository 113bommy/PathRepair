t = int(input())
for i in range(t):
	n = int(input())
	a = [0,0,0,0,0]
	j = 0
	while (n > 0):
		a[j] = n % 10
		n = n // 10
		j += 1
	b = []
	for j in range(5):
		if(a[j] != 0):
			b.append(str(a[j] * pow(10,j)))
	print(len(b))
	print(' '.join(b))