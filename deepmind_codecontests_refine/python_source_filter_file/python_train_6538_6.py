from collections import deque
h, w = map(int, input().split())
A = [input() for _ in range(h)]
dist = [[-1]*w for _ in range(h)]
di = [1, 0, -1, 0]
dj = [0, 1, 0, -1]
que = deque()
for i in range(h):
  for j in range(w):
    if A[i][j] == "#":
      que.append((i, j))
      dist[i][j] = 0
while que:
  y, x = que.popleft()
  for dy, dx in zip(di, dj):
    ny, nx = y+dy, x+dx
    if ny < 0 or ny >= h or nx < 0 or nx >= w:
      continue
    if dist[ny][nx] != -1:
      continue
    dist[ny][nx] = dist[y][x] + 1
    que.append((ny, nx))
ans = 0
for i in dist:
  ans = max(ans, i)
print(ans)