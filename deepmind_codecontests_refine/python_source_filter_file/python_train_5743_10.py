import sys

def swap(row, col, matrix1, matrix2):
	old_val = matrix1[row][col]
	matrix1[row][col] = matrix2[row][col]
	matrix2[row][col] = old_val

def everythingCool(row, col, matrix1, matrix2):
	if col != 0 and (matrix1[row][col-1] > matrix1[row][col] or matrix2[row][col-1] > matrix2[row][col]):
		return False
	if row != 0 and (matrix1[row-1][col] > matrix1[row][col] or matrix2[row-1][col] > matrix2[row][col]):
		return False

	return True

def check_row(row, matrix1, matrix2, row_size, col_size):
	for col in range(col_size):
		if matrix1[row][col] > matrix2[row][col]:
			swap(row, col, matrix1, matrix2)

		if not(everythingCool(row, col, matrix1, matrix2)):
			return False
	return True


size = input().split(" ")

row_size = int(size[0])
col_size = int(size[1])

matrix1 = []
matrix2 = []

for i in range(row_size):
	line = input().split(" ")
	matrix1.append([int(x) for x in line])

for i in range(row_size):
	line = input().split(" ")
	matrix2.append([int(x) for x in line])

for row in range(row_size):
	if not(check_row(row, matrix1, matrix2, row_size, col_size)):
		print("Impossible")
		sys.exit(0)

print("Possible")