from collections import deque
h,w=map(int,input().split())
s=[input() for _ in range(h)]
d=[[1,0],[-1,0],[0,1],[0,-1]]
bcnt=0
for i in range(h):
    bcnt+=s[i].count('#')
dist=[[-1]*w for _ in range(h)]
r=deque()
r.append([0,0])
dist[0][0]=0
while r:
    x,y=r.popleft()
    for dx,dy in d:
        nx=x+dx
        ny=y+dy
        nd=dist[y][x]
        if nx>=0 and nx<=w-1 and ny>=0 and ny<=h-1:
            if dist[ny][nx]>-1 or s[ny][nx]=='#':
                continue
            dist[ny][nx]=nd+1
            r.append([nx,ny])
if dist[h-1][w-1]==-1:
    print(-1)
else:
    print(h*w-dist[h-1][w-1]-1-bcnt)