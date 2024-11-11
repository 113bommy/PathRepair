from collections import deque

h, w = map(int, input().split())
inf = 10 ** 6
a = [[0] * (w + 2)] + [[0] + [inf] * w + [0] for _ in range(h)] + [[0] * (w + 2)]
d = deque()

for i in range(h):
    for j, k in enumerate(input()):
        if k == "#":
            a[i + 1][j + 1] = 0
            d.append((i + 1, j + 1))

stp = ((0, 1), (0, -1), (1, 0), (-1, 0))
res = 0

while d:
    x, y = d.popleft()
    for k, l in stp:
        nx, ny = x + k, y + l
        if a[x][y] + 1 < a[nx][ny]:
            a[nx][ny] = a[x][y] + 1
            res = max(res, a[nx][ny])
            d.append((nx, ny))
print(res)
