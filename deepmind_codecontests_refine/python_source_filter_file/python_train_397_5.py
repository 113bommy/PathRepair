from collections import deque
inf = 10 ** 9 + 7
h, w, k = map(int, input().split())
a = [list(input()) for i in range(h)]
for i in range(h):
    for j in range(w):
        if a[i][j] == "S":
            sx, sy = i, j
d = [(1, 0), (-1, 0), (0, 1), (0, -1)]
l = [[inf] * w for i in range(h)]
l[0][0] = 0
s = set()
s.add((sx, sy))
que = deque([[sx, sy]])
ans = inf
while que:
    x, y = que.popleft()
    if x == 0 or x == h - 1 or y == 0 or y == w - 1:
        ans = 1
        break
    if l[x][y] == k:
        continue
    for i in range(4):
        nx, ny = x + d[i][0], y + d[i][1]
        if nx < 0 or nx >= h or ny < 0 or ny >= w or a[nx][ny] == "#" or l[nx][ny] != inf:
            continue
        s.add((nx, ny))
        l[nx][ny] = l[x][y] + 1
        que.append([nx, ny])
for i in s:
    c = (min(i[0], h - i[0] - 1, i[1], w - i[1] - 1) + k - 1) // k + 1
    ans = min(ans, c)
print(ans)