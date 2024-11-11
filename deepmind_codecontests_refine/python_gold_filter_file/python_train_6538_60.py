from collections import deque
h,w=map(int,input().split())
a=[input() for _ in range(h)]
dxy=[(0,1),(1,0),(-1,0),(0,-1)]
inf=float("inf")

dp=[[inf]*w for _ in range(h)]
q=deque()

for y,l in enumerate(a):
    for x,c in enumerate(l):
        if c=="#":
            dp[y][x]=0
            q.append((x,y))
ans=0
while q:
    x,y=q.popleft()
    d=dp[y][x]
    for dx,dy in dxy:
        nx,ny=x+dx,y+dy
        if not 0<=nx<w: continue
        if not 0<=ny<h: continue
        if dp[ny][nx]<=d+1: continue
        dp[ny][nx]=d+1
        q.append((nx,ny))
        ans=max(ans,d+1)
print(ans)
