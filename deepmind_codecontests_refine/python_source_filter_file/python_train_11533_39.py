from collections import deque
h,w = map(int,input().split())
ch,cw = map(int,input().split())
dh,dw = map(int,input().split())
s = [list(input()) for _ in range(h)]
INF=10**7

queue = deque()

cost = [[INF]*w for _ in range(h)]
cost[ch-1][cw-1]=0

dxdy = [[1,0],[-1,0],[0,1],[0,-1]]
warp = []
for m in range(-2,3):
    for n in range(-2,3):
        if [m,n] not in [[0,0],[1,0],[-1,0],[0,1],[0,-1]]:
            warp += [[m,n]]

queue.append([ch-1,cw-1,0])

while queue:
    x,y,d = queue.popleft()
    if d>cost[x][y]:
        continue
    for dx,dy in dxdy:
        nx,ny = x+dx,y+dy
        if -1<nx<h and -1<ny<w and s[nx][ny]!="#" and d<cost[nx][ny]:
            cost[nx][ny]=d
            queue.appendleft([nx,ny,d])

    for dx,dy in warp:
        nx,ny = x+dx,y+dy
        if -1<nx<h and -1<ny<w and s[nx][ny]!="#" and d+1<cost[nx][ny]:            
            cost[nx][ny]=d+1
            queue.append([nx,ny,d+1])

if cost[dh-1][dw-1]<INF:
    print(cost[dh-1][dw-1])
else:
    print(-1)

