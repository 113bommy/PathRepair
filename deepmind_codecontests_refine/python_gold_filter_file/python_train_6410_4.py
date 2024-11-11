R, C, k, x, y = map(int, input().split())

grid = [[0 for _ in range(C)] for _ in range(R)]

total_in_sweep = R * C + max(R-2, 0) * C
alloc = k // total_in_sweep

for r in range(R):
    for c in range(C):
        grid[r][c] = alloc * (1 if r == 0 or r == R-1 else 2)

k -= alloc * total_in_sweep
r = 0
c = 0

for r in range(R):
    if k <= 0: break
    for c in range(C):
        if k <= 0: break
        k -= 1
        grid[r][c] += 1

for r in range(R-2, -1, -1):
    if k <= 0: break
    for c in range(C):
        if k <= 0: break
        k -= 1
        grid[r][c] += 1

a = max(map(max, grid))
b = min(map(min, grid))
c = grid[x-1][y-1]

print("%d %d %d" % (a, b, c))
