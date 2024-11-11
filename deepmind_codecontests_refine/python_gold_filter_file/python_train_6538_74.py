from collections import deque

h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]

d = [[-1] * w for _ in range(h)]
que = deque()
for i in range(h):
    for j in range(w):
        if a[i][j] == '#':
            que.append((j, i))
            d[i][j] = 0

dxdy = [(1, 0), (-1, 0), (0, 1), (0, -1)]

ans = 0
while que:
    x, y = que.popleft()
    for dx, dy in dxdy:
        nx = x + dx
        ny = y + dy
        if 0 <= nx < w and 0 <= ny < h and d[ny][nx] == -1:
            que.append((nx, ny))
            d[ny][nx] = d[y][x] + 1
            ans = max(ans, d[ny][nx])

print(ans)
