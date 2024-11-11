# F - Pond Skater

from collections import deque

H, W, K = map(int, input().split())
x1, y1, x2, y2 = map(int, input().split())
x1 -= 1
y1 -= 1
x2 -= 1
y2 -= 1
grid = []
for _ in range(H):
    grid.append(list(str(input())))

dist = [[-1] * W for _ in range(H)]
dist[x1][y1] = 0
q = deque()
q.append((x1, y1))

while q:
    (x, y) = q.popleft()
    if (x, y) == (x2, y2):
        break
    for vx, vy in ((0, 1), (1, 0), (0, -1), (-1, 0)):
        for k in range(1, K+1):
            nx = x + vx*k
            ny = y + vy*k
            if nx < 0 or nx >= H or ny < 0 or ny >= W or grid[nx][ny] == '@':
                break
            if dist[nx][ny] != -1 and dist[nx][ny] != dist[x][y] + 1:
                break
            if dist[nx][ny] == -1:
                dist[nx][ny] = dist[x][y] + 1
                q.append((nx, ny))

print(dist[x2][y2])