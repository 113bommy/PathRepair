from collections import deque
h, w = map(int, input().split())
A = [list(input()) for _ in range(h)]
V = [[-1]*w for _ in range(h)]
que = deque([])
for i,a in enumerate(A):
    for j,_a in enumerate(a):
        if _a == '#':
            que.append([i,j])
            V[i][j] = 0
dhdw = [[-1,0],[1,0],[0,-1],[0,1]]
while que:
    nwh,nww = que.popleft()
    for dh, dw in dhdw:
        if not (0<=nwh+dh<h and 0<=nww+dw<w): continue
        if V[nwh+dh][nww+dw] != -1: continue
        V[nwh+dh][nww+dw] = V[nwh][nww]+1
        que.append([nwh+dh, nww+dw])
print(max(map(max, V)))