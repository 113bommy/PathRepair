N = int(input())

for h in range(1, 3501):
	for n in range(1, 3501):
		wb = 4*h*n - N*n - N*h
		if wb <= 0:
			continue
		w = N*h*n / wb
		if w.is_integer():
			print(h, n, int(w))
			exit()