from collections import deque

H, W = map(int, input().split())
Ch, Cw = map(int, input().split())
Dh, Dw = map(int. input().split())
Ch, Cw, Dh, Dw = Ch-1, Cw-1, Dh-1, Dw-1

maze = [input() for _ in range(H)]
visit = [[-1] * W for _ in range(H)]
visit[Ch][Cw] = 0

DQ = deque([[Ch, Cw]])
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

while DQ:
  px, py = DQ.popleft()
  if px==Dh and py==Dw:
    print(visit[px][py])
    exit()
  
  for i in range(4):
    nx = px + dx[i]
    ny = py + dy[i]
    if 0<=nx<=H-1 and 0<=ny<=C-1 and maze[nx][ny]=="." and  (visit[nx][ny]>visit[px][py] or visit[nx][ny]==-1):
      visit[nx][ny] = visit[px][py]
      DQ.append([nx, ny])
    
  for i in range(-2, 3):
    for j in range(-2, 3):
      if i==j==0:
        continue
      nx = px + i
      ny = py + j
      if 0<=nx<=H-1 and 0<=ny<=C-1 and maze[nx][ny]=="." and visit[nx][ny]==-1:
        visit[nx][ny] = visit[px][py] + 1
        DQ.append([nx, ny])

print(-1)