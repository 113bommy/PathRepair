# coding: utf-8
# Your code here!

from collections import deque
from pprint import pprint
moves=[(0,1),(1,0),(0,-1),(-1,0)]
pp=pprint
# INF=float("inf")

h,w,k=map(int,input().split())
x1,y1,x2,y2=map(lambda x:int(x)-1,input().split())
maze=[list(input()) for _ in range(h)]
cost=[[-1]*w for _ in range(h)]

todo=deque()
todo.append((x1,y1))
cost[x1][y1]=0

while todo:
    x,y=todo.popleft()
    for vx,vy in moves:
        for kk in range(1,k+1):
            nx=x+vx*kk
            ny=y+vy*kk
            if not(0<=nx<h) or not(0<=ny<w):
                break
                # 更に伸ばす必要はない
            if maze[nx][ny]=="@":
                break
                # 蓮の向こうにはいけない
            # if cost[nx][ny]!=-1 and cost[nx][ny]<=cost[x][y]:
            #     # 更新を1回以上受けていて、更に良くならない場合はbreak
            #     break
            if cost[nx][ny]==-1:
                cost[nx][ny]=cost[x][y]+1
                todo.append((nx,ny))


# pp(cost)
ans=cost[x2][y2]
print(ans)