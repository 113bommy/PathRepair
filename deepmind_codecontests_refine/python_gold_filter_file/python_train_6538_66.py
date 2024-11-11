from collections import deque

h, w = map(int, input().split())
m = [list(input()) for _ in range(h)]

flag = [[True] * w for _ in range(h)]

q = deque()

for i in range(h):
    for j in range(w):
        if m[i][j] == "#":
            q.appendleft((i, j, 0))
            flag[i][j] = False

ans = 0
while q:
    (i, j, n) = q.pop()
    ans = n
    for dx, dy in zip([1,0, -1, 0], [0, 1, 0, -1]):
        ni = i + dx
        nj = j + dy
        if (0 <= ni < h and 0 <= nj < w and flag[ni][nj]):
            flag[ni][nj] = False
            q.appendleft((ni, nj, n + 1))

print(ans)