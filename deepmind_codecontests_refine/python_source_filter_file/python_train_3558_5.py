def find(n,m,A,B):
	step = []
	for i in range(1,n):
		for j in range(1,m):
			if A[i][j] == 1 and A[i-1][j] == 1 and A[i][j-1] == 1 and A[i-1][j-1] == 1:
				B[i][j] = 1
				B[i-1][j-1] = 1
				B[i][j-1] = 1
				B[i-1][j] = 1
				step.append([i-1,j-1])
	for i in range(n):
		for j in range(m):
			if A[i][j]!=B[i][j]:
				return -1
	return step
n,m = map(int,input().split())
matrix = []
for i in range(n):
	matrix.append(list(map(int,input().split())))
B = [[0 for i in range(m)] for i in range(n)]
step = find(n,m,matrix,B)
if step == -1:
	print(-1)
else:
	print(len(step))
	for i in step:
		print(i[0],i[1])
