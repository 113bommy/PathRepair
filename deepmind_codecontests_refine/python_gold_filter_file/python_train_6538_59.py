from collections import deque

h,w = map(int,input().split())
m = [input() for _ in range(h)]
vm  = [[-1] * w for _ in range(h) ]

q = deque()

for i in range(h):
    for j in range(w):
        if m[i][j] == '#':
            q.append((i,j))
            vm[i][j]=0

while q:
    y,x = q.popleft()
    d = vm[y][x]

    for i,j in ([1, 0], [-1, 0], [0, 1], [0, -1]):
        yi , xj = y + i , x + j
        if yi >= 0 and xj >= 0 and yi < h and xj < w and vm[yi][xj] == -1 :
            vm[yi][xj] = d +  1
            q.append([yi,xj])
            

print(d)
