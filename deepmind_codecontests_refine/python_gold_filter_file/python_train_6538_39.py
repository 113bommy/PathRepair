from collections import deque


h, w = map(int, input().split())
grid = [input() for _ in range(h)]
cost = [[-1] * w for _ in range(h)]
nb = [(-1, 0), (0, -1), (1, 0), (0, 1)]

q = deque()
for i in range(h):
    for j in range(w):
        if grid[i][j] == "#":
            q.append((i, j))
            cost[i][j] = 0

while q:
    x, y = q.popleft()
    for dx, dy in nb:
        nx = x + dx
        ny = y + dy
        if 0 <= nx and nx < h and 0 <= ny and ny < w and cost[nx][ny] == -1:
            cost[nx][ny] = cost[x][y] + 1
            q.append((nx, ny))


print(max([max(c) for c in cost]))