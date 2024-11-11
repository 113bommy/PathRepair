H,W = map(int,input().split())
s = []
black = 0
for i in range(H):
    l = list(input())
    for j in range(W):
        if l[j] == "#":
            black += 1
    s.append(l)
white = H*W-black
from collections import deque
q = deque([(0,0,0)])
s[0][0] = "#"
while q:
    x,y,cnt = q.popleft()
    for dx,dy in [(0,1),(0,-1),(1,0),(-1,0)]:
        nx,ny = x+dx,y+dy
        if 0<=nx<H and 0<=ny<W and s[nx][ny] != "#":
            if nx == H-1 and ny == W-1:
                print(white-cnt-2)
                exit(0)
            s[nx][ny] = "#"
            q.append((nx,ny,cnt+1))
print(-1)