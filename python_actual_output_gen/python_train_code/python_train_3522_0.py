def calc(grid):
    n = [["1" for y in range(3)] for x in range(3)]
    for row in range(len(grid)):
        for col in range(len(grid[0])):
            update(n, grid, row, col)
    return n
def update(n, grid, row, col):
    c = grid[row][col]
    c %=2
    if c != 0:
        # toggle adjacent lights
        for nr, nc in zip([row-1, row+1, row, row], [col, col, col-1,col+1]):
            if nr>=0 and nr<len(n) and nc>=0 and nc<len(n[0]):
                n[nr][nc] = "1" if n[nr][nc] == "0" else "0"
        n[row][col] = "1" if n[row][col] == "0" else "0"

# get inputs
grid = []
for _ in range(3):
    grid.append(list(map(int, input().split())))
n = calc(grid)
for row in n:
    print(' '.join(row))





