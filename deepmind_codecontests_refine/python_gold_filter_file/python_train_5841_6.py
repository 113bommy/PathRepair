
from collections import deque
moves = [(-1, 0), (1,0), (0,1), (0, -1), (1,1), (-1,-1), (-1, 1), (1, -1)]

def get_neighbors(row, col, q, n):
	res = []
	for x,y in moves:
		new_x = x + row
		new_y = y + col
		if new_x >= 0 and new_x < n:
			if new_y >= 0 and new_y < n:
				if abs(new_x - q[0]) != abs(new_y - q[1]):
					if new_y != q[1] and new_x != q[0]:
						res.append([new_x, new_y])
	return res



def solve(n, queen, king, target):
	visited = [[-1] * (n + 1) for _ in range(n + 1)]

	def _bfs(start):
		if start == target:
			print("YES")
			return
		x,y  = start
		visited[x][y] = 1
		q = deque()
		q.append(start)

		while len(q):
			row, col = q.popleft()
			if row == target[0] and col == target[1]:
				print("YES")
				return
			neighbors = get_neighbors(row,col, queen, n + 1)
			for x,y in neighbors:
				if visited[x][y] == -1:
					visited[x][y] = 1
					q.append([x,y])
		print("NO")
		return 
	_bfs([king[0], king[1]])	


dimensions = int(input())
queen = list(map(int, input().split(" ")))
king = list(map(int, input().split(" ")))
target = list(map(int, input().split(" ")))

solve(dimensions, queen, king, target)
