H,W = map(int, input().split())
grid = []
for i in range(H):
    grid.append(input())
horiz = [[0]*W for _ in range(H)]
for i in range(H):
    cur = 0
    for j in range(W):
        if grid[i][j] == '#':
            for k in range(cur, j):
                horiz[i][k] = j-cur
            cur = j+1
    for k in range(cur, W):
        horiz[i][k] = W-cur

maxv = 0
for c in range(W):
    cur = 0
    besth = 0
    for r in range(H):
        if grid[r][c] == '.':
            besth = max(besth, horiz[r][c])
        else:
            maxv = max(maxv, r-cur + besth - 1)
            cur = r+1
            besth = 0
    maxv = max(maxv, H-cur + besth - 1)

print(maxv)