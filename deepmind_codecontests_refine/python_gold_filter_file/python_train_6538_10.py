from collections import deque

h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]

q = deque()

for i in range(h):
    for j in range(w):
        if a[i][j] == '#':
            q.append((i, j, 0)) 

while q:
    y, x, d = q.popleft()
    if a[y][x] == '#':
        for xdx, ydy in zip((x, x, x+1, x-1), (y+1, y-1, y, y)):
            if (0 <= xdx < w) and (0 <= ydy < h):
                if a[ydy][xdx] == '.':
                    a[ydy][xdx] = '#'
                    q.append((ydy, xdx, d+1))
print(d)