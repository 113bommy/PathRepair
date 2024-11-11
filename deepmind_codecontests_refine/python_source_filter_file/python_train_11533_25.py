from collections import deque

H,W=map(int,input().split())
ch,cw=map(int,input().split())
dh,dw=map(int,input().split())
S=[input() for _ in range(H)]
visited=[[-1]*W for _ in range(H)]
visited[ch-1][cw-1]=0
h=deque([(ch-1,cw-1)])
c=0
while 1:
  done=[]
  while h:
    cx,cy=h.popleft()
    done.append((cx,cy))
    for dx,dy in [(0,1),(1,0),(0,-1),(-1,0)]:
      nx,ny = cx+dx,cy+dy
      if 0<=nx<H and 0<=ny<W and S[nx][ny]=='.' and visited[nx][ny]==-1:
        h.append((nx,ny))
        visited[nx][ny]=c
  for cx,cy in done:
    for dx in range(-2,3):
      for dy in range(-2,3):
        nx,ny = cx+dx,cy+dy
        if 0<=nx<H and 0<=ny<W and S[nx][ny]=='.' and visited[nx][ny]==-1:
          h.append((nx,ny))
          visited[nx][ny]=c+1
  if not h or visited[dh-1][dw-1]!=-1:
    break
  c+=1
print(visited[dh-1][dw-1])