import sys

h, w = [int(x) for x in input().split()]
r = [int(x) for x in input().split()]
c = [int(x) for x in input().split()]

MOD = 1000000007

UNKNOWN = 0
WHITE = 1
BLACK = 2

grid = [[UNKNOWN for _ in range(w)] for _ in range(h)]

for i, ri in enumerate(r):
    for x in range(ri):
        grid[i][x] = BLACK
    if ri < w:
        grid[i][ri] = WHITE

for i, ci in enumerate(c):
    for x in range(ci):
        if grid[x][i] == UNKNOWN:
            grid[x][i] = BLACK
        elif grid[x][i] == BLACK: continue
        elif grid[x][i] == WHITE:
            print(0)
            sys.exit(0)
    if ci < h:
        if grid[x][i] == UNKNOWN:
            grid[x][i] = WHITE
        elif grid[x][i] == WHITE: continue
        elif grid[x][i] == BLACK:
            print(0)
            sys.exit(0)

# print(grid)
unknowns = sum(sum(int(x==UNKNOWN) for x in Y) for Y in grid)
print(pow(2, unknowns, MOD))