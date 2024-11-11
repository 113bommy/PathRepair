from collections import deque
import sys
sys.setrecursionlimit(1000000)

H,W = map(int,input().split())
curX,curY = map(int,input().split())
curX -= 1
curY -= 1
goalX,goalY =  map(int,input().split())
goalX -= 1
goalY -= 1

graph = [ list(input()) for _ in range(H) ]
q = deque([(curX,curY)])
dist = [ [float('inf')]*W for _ in range(H) ]
dist[curX][curY] = 0

while q:
  r,c = q.popleft()
  if r==goalX and c==goalY: break
  hop = dist[r][c]

  # if be able to move 1 step
  for x,y in [(1,0),(-1,0),(0,1),(0,-1)]:
    nr,nc = r+x,c+y
    if 0<=nr<H and 0<=nc<W and graph[nr][nc]!="#" and dist[nr][nc]>hop:
      dist[nr][nc] = hop
      q.append((nr,nc))

  for i in range(-2, 3):
    for j in range(-2, 3):
      nr,nc = r+i,c+j
      if 0<=nr<H and 0<=nc<W and graph[nr][nc]!="#" and dist[nr][nc]>hop+1:
        dist[nr][nc] = hop+1
        q.append((nr,nc))

ans = dist[goalX][goalY]
if ans == float('inf'):
  print(-1)
else:
  print(ans)