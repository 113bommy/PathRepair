t,*l=open(0)
h,w=map(int,t.split())
grid = [[c=="."for c in C]for C in l]
L,R,U,D = eval("[[0]*(w+2) for _ in range(h+2)],"*4)
for y in range(h):
	for x in range(w):
		L[y+1][x+1] = (L[y+1][x]+1)*grid[y][x]
		R[y+1][w-x] = (R[y+1][w-x+1]+1)*grid[y][w-x-1]
for x in range(w):
	for y in range(h):
		U[y+1][x+1] = (U[y][x+1]+1)*grid[y][x]
		D[h-y][x+1] = (D[h-y+1][x+1]+1)*grid[h-y-1][x]
print(max(L[y][x] + R[y][x] + U[y][x] + D[y][x] -3 for y in range(1,h+1) for x in range(1,w+1)))