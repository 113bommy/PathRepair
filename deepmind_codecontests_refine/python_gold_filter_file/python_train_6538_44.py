from collections import deque
h, w = map(int, input().split())
a = []
for _ in range(h):
    a.append(list(input()))
q = deque()
for i in range(h):
    for j in range(w):
        if a[i][j]=='#':
            q.append((i, j, 0))
dxdy = [(-1, 0), (0, -1), (0, 1), (1, 0)]
ans = 0
while q:
    y, x, cnt = q.popleft()
    for dx, dy in dxdy:
        if not(0<=x+dx<w and 0<=y+dy<h):
            continue
        if a[y+dy][x+dx]=='.':
            a[y+dy][x+dx] = '#'
            q.append((y+dy, x+dx, cnt+1))
            ans = cnt+1
print(ans)