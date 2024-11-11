from collections import deque

he,w,k = map(int,input().split())
sx,sy,gx,gy = map(int,input().split())
l = [list(input()) for i in range(he)]

sx -= 1
sy -= 1
gx -= 1
gy -= 1
q = deque([])
d = [[float("INF")]*w for i in range(he)]
dx = [1,-1,0,0]
dy = [0,0,1,-1]
d[sx][sy] = 0
q.append((0,sx,sy))
while q:
    dis,bx,by = q.popleft()
    if bx == gx and by == gy:
        continue
    for i in range(4):
        for j in range(1,k+1):
            nx = bx+dx[i]*j
            ny = by+dy[i]*j
            if 0 > nx or 0 > ny or nx >= he  or ny >= w:
                break
            if l[nx][ny] == "@":
                break
            if d[nx][ny] <= dis:
                break
            if d[nx][ny] > dis+1:
                d[nx][ny] = dis+1
                q.append((dis+1,nx,ny))

if d[gx][gy] == float("INF"):
    print(-1)
else:
    print(d[gx][gy])
