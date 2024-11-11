from collections import deque

h, w = map(int, input().split())
c = []
d = [[-1 for i in range(w)] for j in range(h)]
q = deque()
for i in range(h):
	s = input()
	c.append(s)
	for j in range(w):
		if c[i][j] == '#':
			q.append([i, j, 0])
			d[i][j] = 0

dirr = [[1, 0], [0, 1], [-1, 0], [0, -1]]

while len(q) != 0:
	y, x, z = q[0]

	for i in range(4):
		ny, nx = y + dirr[i][0], x + dirr[i][1]
		if 0 <= ny < h and 0 <= nx < w and d[ny][nx] == -1 and c[ny][nx] != "#":
			q.append([ny, nx, z + 1])
			d[ny][nx] = z + 1

	q.popleft()

print(z)

