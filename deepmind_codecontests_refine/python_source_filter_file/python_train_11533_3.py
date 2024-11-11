from collections import*
INF=10**18
h,w=map(int,input().split())
sh,sw=map(int,input().split())
gh,gw=map(int,input().split())
s=[input() for _ in range(h)]
q=deque([(sh-1,sw-1,1)])
d=[[INF]*w for _ in range(h)]
dx=[1,0,-1,0]
dy=[0,-1,0,1]
wx=[-2,-1,0,1,2]
wy=[-2,-1,0,1,2]
while q:
  x,y,c=q.popleft()
  if d[x][y]!=INF:continue
  d[x][y]=c
  for i,j in zip(dx,dy):
    nx=x+i
    ny=y+j
    if not(0<=nx<h and 0<=ny<w):continue
    if s[nx][ny]=='.' and d[nx][ny]==INF:
      q.appendleft((nx,ny,c))
  for i in wx:
    nx=x+i
    if not(0<=nx<h):continue
    for j in wy:
      ny=y+j
      if not(0<=ny<w):continue
      if s[nx][ny]=='.' and d[nx][ny]==INF:
        q.append((nx,ny,c+1))
print(d[gh-1][gw-1]if d[gh-1][gw-1]==INF else -1)