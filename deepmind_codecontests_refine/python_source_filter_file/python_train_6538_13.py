#AGC033-A-Darker and Darker
from collections import deque

h,w = map(int,input().split())
grid = [input() for i in range(h)]

#初期の黒('#')の位置からの距離
dist = [[-1]*w for _ in range(h)]

p = deque()
d = 0
for i in range(h):
    for j in range(w):
        if grid[i][j] == '#':
            p.append((i,j))
            dist[i][j] = 0

while p:
    x,y = p.popleft()
    d = dist[x][y]
    for dy,dx in ((1,0),(0,1),(-1,0),(0,-1)):
        if 0<= x+dx < w and 0<= y+dy < h and dist[y+dy][x+dx] == -1:
            dist[y+dy][x+dx] = d+1
            p.append((y+dy,x+dx))

    
print(d)