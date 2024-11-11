H, W = map(int, input().split())
S = [list(input()) for _ in range(H)]
diff = [-1, 0, 1]
for i in range(H):
	for j in range(W):
		count = 0
		for x in diff:
			for y in diff:
				if 0 < i + x < H and 0 < j + y < W and S[i+x][j+y] == '#':
					count += 1
		if S[i][j] == '.':
			S[i][j] = count
for s  in S:
	print(''.join(map(str, s)))