n = int(input().strip())
grid = [list(input().strip()) for _ in range(n)]
def solve(grid, n):
	s1 = grid[0][0]
	s2 = grid[0][1]
	if s1 == s2:
		return False
	for i in range(n):
		for j in range(n):
			if i == 0 and j == 0:	continue
			if (i == j or n-i-1 == j) and grid[i][j] != s1:
				return 'NO'
			elif (i != j and n-i-1 != j) and grid[i][j] != s2:
				return 'NO'
	return 'YES'
print(solve(grid, n))