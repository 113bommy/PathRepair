


def main():
	n, m = map(int, input().split())
	grid = [list(map(int, input().split())) for _ in range(n)]
	visited = [[False] * m for _ in range(n)]
	rooms = []

	for i in range(n):
		for j in range(m):
			if visited[i][j]: continue
			room_size = 0
			stack = [(i, j)]
			while stack:
				x, y = stack.pop()
				if visited[x][y]: continue
				visited[x][y] = True
				room_size += 1
				# up 
				if x > 0 and not (grid[x][y] & 8 or grid[x-1][y] & 2):
					stack.append((x-1 , y))
				# right
				if y < m and not (grid[x][y] & 4 or grid[x][y+1] & 1):
					stack.append((x, y+1))
				# down
				if x < n and not (grid[x][y] & 2 or grid[x+1][y] & 8):
					stack.append((x+1, y))
				# left
				if y > 0 and not (grid[x][y] & 1 or grid[x][y-1] & 4):
					stack.append((x, y-1))

			rooms.append(room_size)

	rooms.sort(reverse=True) 

	print(' '.join(map(str, rooms)))




	

if __name__ == '__main__':
	main()