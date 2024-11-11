from collections import deque
h,w=map(int,input().split())
S=[input() for _ in range(h)]

ans=0
dxy=[(0,1),(1,0),(0,-1),(-1,0)]
for x in range(w):
  for y in range(h):
    if S[y][x]=='#': continue
    q=deque([(x,y)])
    dist=[[0]*w for _ in range(h)]
    visited=[[0]*w for _ in range(h)]
    visited[y][x]=1
    while q:
      x,y=q.popleft()
      for dx,dy in dxy:
        nx,ny=x+dx,y+dy
        if not 0<=nx<w: continue
        if not 0<=ny<h: continue
        if visited[ny][nx]: continue
        if S[ny][nx]=='#': continue
        visited[ny][nx]=1
        dist[ny][nx]=dist[y][x]+1
        q.append((nx,ny))
    ans = max(ans, max(max(row) for row in dist))
print(ans)