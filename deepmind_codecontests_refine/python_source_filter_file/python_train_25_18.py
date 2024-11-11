for _ in range(int(input())):
	n = int(input())
	grid = [input() for i in range(n)]
	moves = []

	def set_to(i, j, val):
		if grid[i][j] != val:
			moves.append((i+1,j+1))
	def other(x):
		return '0' if x=='1' else '1'


	if grid[0][1] == grid[1][0]:
		for i,j in [(n-2,n-1),(n-1,n-2)]:
			set_to(i,j,other(grid[0][1]))
	elif grid[n-2][n-1] == grid[n-1][n-2]:
		for i,j in [(0,1),(1,0)]:
			set_to(i,j,other(grid[n-2][n-1]))
	else:
		for i,j in [(0,1),(1,0)]:
			set_to(i,j,0)
		for i,j in [(n-2,n-1),(n-1,n-2)]:
			set_to(i,j,1)

	print(len(moves))
	for move in moves:
		print(*move)