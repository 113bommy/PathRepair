from collections import deque

H,W=map(int,input().split())
field=[]
dist=[[-1]*W for _ in range(H)]
que=deque()

for i in range(H):
    tmp=list(input())
    for j in range(W):
        if tmp[j]=="#":
            dist[i][j]=0
            que.append([i,j])
    field.append(tmp)

DX=[1,0,-1,0]
DY=[0,1,0,-1]
ans=0
while que:
    y,x=map(int,que.popleft())
    ans=dist[y][x]
    for dx,dy in zip(DX,DY):
        nx=x+dx
        ny=y+dy
        if nx<0 or nx>=W or ny<0 or ny>=H: continue
        if dist[ny][nx]==-1:
            dist[ny][nx]=dist[y][x]+1
            que.append([ny,nx])

print(ans)
