import sys
input=sys.stdin.readline
from collections import deque
h,w=map(int,input().split())
MAP=[list(input().strip()) for _ in range(h)]
q=deque()
for i,M in enumerate(MAP):
    for j,m in enumerate(M):
        if m=='#':
            q.append((i,j,0))
delta=[(1,0),(-1,0),(0,1),(0,-1)]
ans=0
while q:
    x,y,d=q.popleft()
    ans=max(ans,d)
    for dx,dy in delta:
        if 0<=x+dx<h and 0<=y+dy<w:
            if MAP[x+dx][y+dy]=='.':
                MAP[x+dx][y+dy]='#'
                q.append((x+dx,y+dy,d+1))
print(ans)