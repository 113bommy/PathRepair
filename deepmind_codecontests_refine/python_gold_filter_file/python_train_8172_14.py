def main():
	n = int(input())
	points = set()
	for i in range(n):
		(row, col) = (int(x) for x in input().split())
		points.add((row, col))
	print(solver(points, 1000))


def solver(S, size):
	diagonals = [[0] for i in range(size)]
	diagonals[0] = [0] * size

	antiDiagonals = [[0] for i in range(size)]
	antiDiagonals[size - 1] = [0] * size

	for point in S:
		(row1, col1) = getDiagonal(point, size)
		diagonals[row1][col1] += 1
		(row2, col2) = getAntiDiagonal(point, size)
		antiDiagonals[row2][col2] += 1

	total = 0
	#print(diagonals)
	#print(antiDiagonals)
	# diagonals
	for j in range(size):
		total += nChoose2(diagonals[0][j])
	for i in range(1, size):
		total += nChoose2(diagonals[i][0])
	# antiDiagonals
	for j in range(size):
		total += nChoose2(antiDiagonals[size-1][j])
	for i in range(size - 1):
		total += nChoose2(antiDiagonals[i][0])

	return total

def getDiagonal(point, size):
	(row, col) = point
	if row < col:
		return (0, col - row)
	else:
		return (row - col, 0)

def getAntiDiagonal(point, size):
	(row, col) = (point[0] - 1 , point[1] - 1)
	total = row + col
	if total < size:
		return (total, 0)
	else:
		return (size - 1, total - size + 1)

def nChoose2(n):
	return n * (n - 1) // 2

main()

points = {(1, 1), (1, 5), (3, 3), (5, 1), (5, 5)}
points2 = {(1, 1), (2, 3), (3, 5)}
#print(solver(points2, 5))