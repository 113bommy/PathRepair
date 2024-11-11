from sys import stdin

n, k = map(int, stdin.readline().strip().split())

grid = []
for i in range(n):
    grid.append(stdin.readline().strip())

counts = []
for i in range(n):
    counts.append([0] * n)

def fits(i, j, di, dj, k):
    for delta in range(k):
        if grid[i + delta * di][j + delta * dj] == '#':
            return False
    return True

def mark(i, j, di, dj, k):
    for delta in range(k):
        counts[i + delta * di][j + delta * dj] += 1

for i in range(n - k + 1):
    for j in range(n):
        if fits(i, j, 1, 0, k):
            mark(i, j, 1, 0, k)

for i in range(n):
    for j in range(n - k + 1):
        if fits(i, j, 0, 1, k):
            mark(i, j, 0, 1, k)

max_count = 0
max_row, max_col = 0, 0
for i in range(n):
    for j in range(n):
        if counts[i][j] > max_count:
            max_count = counts[i][j]
            max_row = i + 1
            max_col = j + 1

print(max_row, max_col)
