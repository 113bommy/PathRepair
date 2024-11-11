
H, W = map(int, input().split())
maze = [list(input()) for _ in range(H)]
# print(maze)

blacks = []
for i in range(H):
    for j in range(W):
        if maze[i][j] == '#':
            blacks.append((i, j))
# print(blacks)

count = 0
while len(blacks) != 0:
    count += 1
#     print(blacks)
    nexts = []
    for x, y in blacks:
        for nx, ny in [(x-1, y), (x+1,y), (x,y-1),(x,y+1)]:
            if 0<=nx<H and 0<=ny<W and maze[nx][ny] == '.':
                maze[nx][ny] = '#'
                nexts.append((nx, ny))
#     print(maze)
    blacks = nexts
    
print(count-1)