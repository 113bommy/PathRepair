from collections import deque

h, w = map(int,input().split())
alist = [input().strip() for i in range(h)]
dxy = [(0,1),(1,0),(0,-1),(-1,0)]

INF = 99999
dp = [[INF]*w for i in range(h)]
q = deque()
for y, row in enumerate(alist):
  for x, c in enumerate(row):
    if c=='#':
      dp[y][x] = 0
      q.append((x,y))

while q:
  x, y = q.popleft()
  d = dp[y][x]
  for dx, dy in dxy:
    nx, ny = x+dx, y+dy
    if not 0 <= nx < w:
      continue
    if not 0 <= ny < h:
      continue
    if dp[ny][nx] <= d+1:
      continue
    dp[ny][nx] = d+1
    q.append((nx,ny))

print(max(max(row) for row in dp))
