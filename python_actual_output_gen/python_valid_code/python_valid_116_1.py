X = int(input())
for i in range(1, X):
	if i * (i - 1) / 2 < X <= i * (i + 1) / 2:
		print(i)
		exit()
