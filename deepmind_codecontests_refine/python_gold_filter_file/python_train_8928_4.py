from collections import deque

H, W, K = map(int,input().split())
x1,y1,x2,y2 = map(int,input().split())
c = list(list(input())for _ in range(H))
cost = [[H*W+1]*W for _ in range(H)]
cost[x1-1][y1-1] = 0
queue = deque([[x1-1,y1-1]])
while queue:
    x,y = queue.popleft()
    for vecx,vecy in [[0,1],[1,0],[-1,0],[0,-1]]:
        for k in range(1,K+1):
            nx,ny = x+k*vecx, y+k*vecy
            if not(0<=nx<H) or not(0<=ny<W):
                break
            if c[nx][ny] == '@':
                break
            if cost[nx][ny] > cost[x][y]+1:
                cost[nx][ny] = cost[x][y]+1
                queue.append([nx,ny])
            elif cost[nx][ny] < cost[x][y]+1:
                break
if cost[x2-1][y2-1] == H*W+1:
    print(-1)
else:
    print(cost[x2-1][y2-1])


