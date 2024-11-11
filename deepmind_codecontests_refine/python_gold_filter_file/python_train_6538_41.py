h,w = map(int,input().split())
a = list(list(input())for i in range(h))
stack = []
for i in range(h):
    for j in range(w):
        if a[i][j] == "#":
            stack.append((i,j))
        
vec = ((1,0),(0,1),(-1,0),(0,-1))
move = 0
while stack:
    next = []
    move +=1
    for y,x in stack:
        for ny,nx in vec:
            ty,tx = y+ny,x+nx
            if ty>h-1 or tx>w-1 or ty<0 or tx <0:continue
            if a[ty][tx] == ".":
                a[ty][tx] = move
                next.append((ty,tx))
    stack = next

print(move-1)
