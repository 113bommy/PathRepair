from collections import deque
h,w=map(int,input().split())
INF=10**18
a=[input() for _ in range(h)]
d=[[INF for _ in range(w)]for _ in range(h)]
q=deque([])
for i in range(h):
  for j in range(w):
    if a[i][j]=='#':
      d[i][j]=0
      q.append((i,j))
dx=[1,0,-1,0]
dy=[0,1,0,-1]
ans=0
while q:
  x,y=q.popleft()
  for i in range(4):
    nx=x+dx[i]
    ny=y+dy[i]
    if 0<=nx<h and 0<=ny<w:
      if d[nx][ny]==INF:
        q.append((nx,ny))
        d[nx][ny]=d[x][y]+1
        ans=max(ans,d[nx][ny])
print(ans)