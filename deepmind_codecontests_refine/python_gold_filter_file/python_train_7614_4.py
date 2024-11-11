n, m, h = [int(i) for i in input().split()]
col = [int(i) for i in input().split()]
row = [int(i) for i in input().split()]
mat = [[int(i) for i in input().split()] for _ in range(n)]
for i in range(n):
	for j in range(m):
		if mat[i][j] != 0:
			mat[i][j] = max(mat[i][j], min(row[i], col[j]))
print('\n'.join(' '.join(str(i) for i in line) for line in mat))