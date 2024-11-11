def main():
	n = int(input())
	grid = [None] * n
	for i in range(n):
		grid[i] = str(input())
	print(solver(grid))

def solver(grid):
	n = len(grid)
	total = 0 
	for row in range(n):
		Cs = grid[row].count('C')
		total += nC2(Cs)
	for col in range(n):
		Cs = 0
		for row in range(n):
			if grid[row][col] == 'C':
				Cs += 1
		total += nC2(Cs)
	return total

def nC2(n):
	if n < 2:
		return 0
	else:
		return n * (n - 1) // 2

print([None] * 4)
#main()
#print("3332".count('3'))
#grid = [".CC", "C..", "C.C"]
#print(solver(grid))