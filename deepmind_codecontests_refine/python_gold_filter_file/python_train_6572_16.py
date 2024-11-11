matrix_size=input()

matrix=[]

matrix_size=int(matrix_size)
for i in range(matrix_size):
	matrix.append(input())


ans=0


for i in range(1,matrix_size-1):
	for j in range(1,matrix_size-1):
		if matrix[i][j]=='X' and matrix[i-1][j-1]=='X' and matrix[i-1][j+1]=='X' and matrix[i+1][j-1]=='X' and matrix[i+1][j+1]=='X':
			ans+=1

print (ans)