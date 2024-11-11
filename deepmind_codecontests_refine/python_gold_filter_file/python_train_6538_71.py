from collections import deque

dyx = [(0, 1), (0, -1), (1, 0), (-1, 0)]
H, W = map(int, input().split())
edge = ['#']*(W+2)
field = [edge]
q = deque()

for i in range(H):
    field.append(['#'] + list(input()) + ['#'])
    for j in range(W):
        if field[i+1][j+1] == '#':
            q.append((i+1, j+1, 0))
field.append(edge)
res = 0

while q:
    y, x, lv = q.popleft()
    res = max(lv, res)

    for dy, dx in dyx:
        if field[y+dy][x+dx] == '.':
            field[y+dy][x+dx] = '#'
            q.append((y+dy, x+dx, lv+1))

print(res)
