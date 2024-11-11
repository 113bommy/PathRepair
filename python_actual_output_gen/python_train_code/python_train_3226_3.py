n = int(input())

A = [[0 for i in range(n)] for j in range(n)]

for i in range(n):

	B = input().split()

	if B[1]!=0:
		for j in range(int(B[1])):
			#B[2+j]
			A[i][int(B[2+j])-1] = 1

for i in range(n):
	for j in range(n):
		if j!=n-1:
			print(A[i][j], end=" ")
		else:
			print(end="\n")
