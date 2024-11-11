#!/usr/bin/env python3

n, k = map(int, input().split(' '))

grid = []
for i in range(n):
	grid.append(input().rstrip())

counts = [[0]*n for i in range(n)]

for i in range(0, n):
	for j in range(0, n-k+1):
		if all(grid[i][j+dj] == '.' for dj in range(k)):
			for dj in range(k):
				counts[i][j+dj] += 1

for j in range(0, n):
	for i in range(0, n-k+1):
		if all(grid[i+di][j] == '.' for di in range(k)):
			for di in range(k):
				counts[i+di][j] += 1

m = 0
mp = (0, 0)

for i in range(n):
	for j in range(n):
		if counts[i][j] > m:
			m = counts[i][j]
			mp = (i+1, j+1)

print(*mp)