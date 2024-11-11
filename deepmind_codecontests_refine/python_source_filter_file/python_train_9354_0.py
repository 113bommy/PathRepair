h, w = map(int, input().split())
ls = [input().split() for _ in range(h)]

for i in range(h):
	for j in range(w):
		if ls[i][j] == 'snuke':
			print(chr(65 + i) + str(j + 1))
			break