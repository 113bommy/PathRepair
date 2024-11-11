n, m ,l = map(int, input().split())

A = [list(map(int,input().split())) for i in range(n)]
B = [list(map(int,input().split())) for j in range(m)]

C = [[0 for i in range(l)] for j in range(n)]

for i in range(l):
	for j in range(n):
		for k in range(m):
			C[i][j] + = (A[i][k] * B[k][j])

Cp = [print(" ".join(map(str, C[i]))) for i in range(n)]