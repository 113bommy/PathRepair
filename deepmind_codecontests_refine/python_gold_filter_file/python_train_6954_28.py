h,w = map(int,input().split())
grid = [[c=="."for c in input()]for _ in range(h)]
L,R,U,D = eval("[[0]*(w+2) for _ in range(h+2)],"*4)
for y in range(h):
	for x in range(w):
		if grid[y][x]:
			L[y+1][x+1] = L[y+1][x]+1
		if grid[y][w-x-1]:
			R[y+1][w-x] = R[y+1][w-x+1]+1
for x in range(w):
	for y in range(h):
		if grid[y][x]:
			U[y+1][x+1] = U[y][x+1]+1
		if grid[h-y-1][x]:
			D[h-y][x+1] = D[h-y+1][x+1]+1
a = 0
for y in range(1,h+1):
	for x in range(1,w+1):
		a = max(a, L[y][x] + R[y][x] + U[y][x] + D[y][x] -3)
print(a)