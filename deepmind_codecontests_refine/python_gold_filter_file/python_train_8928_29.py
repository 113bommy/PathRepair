h,w,k = map(int, input().split())
sx,sy,gx,gy = map(int, input().split())
sx-=1
sy-=1
gx-=1
gy-=1

grid = ['' for _ in range(h)]

for i in range(h):
    grid[i] = input()
INF = 1001001001  
costgrid = [[INF]*w for _ in range(h)]

import heapq

q = []
q.append((0,sx,sy))

dx = (0,1,0,-1)
dy = (1,0,-1,0)
ans=INF
while q:
    cost,x,y = heapq.heappop(q)
    for i in range(4):
        for j in range(1,k+1):
            nx = x+dx[i]*j
            ny = y+dy[i]*j
            if(not 0<=nx<h):
                break
            if(not 0<=ny<w):
                break
            if(grid[nx][ny]=='@'):
                break
            if(costgrid[nx][ny]<=cost):
                break
            if(costgrid[nx][ny]>cost+1):
                costgrid[nx][ny]=cost+1
                heapq.heappush(q,(cost+1,nx,ny))
                if nx==gx and ny==gy:
                    ans=min(costgrid[nx][ny],ans)
                    q=[]

if ans!=INF:
    print(ans)
else:
    print(-1)

