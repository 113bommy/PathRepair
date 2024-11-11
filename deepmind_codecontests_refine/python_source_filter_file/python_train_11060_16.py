t = int(input())
for i in range(t):
	n = int(input())
	if n % 4 != 0:
		print("NO")
	else:
		print("Yes")
		a = [0] * (n // 2)
		b = [0] * (n // 2)
		for j in range(n // 2):
			a[j] = j * 2 + 1
		for j in range(n // 2):
			b[j] = j * 2 + 2
		a[-1] += n // 2
		b += a
		print(b)