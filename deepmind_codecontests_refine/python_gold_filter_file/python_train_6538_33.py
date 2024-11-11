from collections import deque

H, W = map(int,input().split())
coords = []
blacks = deque([])
for i in range(H):
    rows = list(input())
    coords.append(rows)
    for j,row in enumerate(rows):
        if row == "#":
            blacks.append((i,j,0))

ans = 0
while len(blacks) > 0: 
    h,w,dist = blacks.popleft()
    ans = max(dist,ans)
    for di, dj in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
        ni = h + di
        nj = w + dj
        if 0 <= ni < H and 0 <= nj < W:
            if coords[ni][nj] == ".":
                blacks.append((ni,nj,dist+1))
                coords[ni][nj] = "#"

print(ans)