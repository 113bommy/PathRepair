from collections import deque

H, W = map(int, input().split())
A = [input() for i in range(H)]

Map = [[-1] * W for i in range(H)]

d = deque([])
for i in range(H):
  for j in range(W):
    if A[i][j] == '#':
      Map[i][j] = 0
      d.append([i, j])

ans = 0
while d:
  x, y = d.popleft()
  dist = Map[x][y]
  for dx, dy in [[1, 0], [0, 1], [-1, 0], [0, -1]]:
    u, v = x + dx, y + dy
    if 0<=u<H and 0<=v<W and Map[u][v]==-1:
      Map[u][v] = dist + 1
      ans = max(ans, dist + 1)
      d.append([u, v])

print(ans)