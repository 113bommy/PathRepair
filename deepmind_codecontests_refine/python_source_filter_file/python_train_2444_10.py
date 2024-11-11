import sys
sys.setrecursionlimit(10000)

def dfs(x,y,xprev,yprev):
    global vst
    if vst[x][y]:
        return
    vst[x][y] = True
    for dx, dy in [(0,1),(0,-1),(1,0),(-1,0)]:
        xprime = x + dx
        yprime = y + dy
        if 0<=xprime<n and 0<=yprime<m:
            if color[x][y] == color[xprime][yprime]\
                and ((xprime,yprime) != (xprev, yprev)):
                if vst[xprime][yprime]:
                    #print(vst)
                    #print(x,y,xprime, yprime)
                    print('YES')
                    sys.exit(0)
                else:
                    dfs(xprime, yprime, x, y)

n, m = tuple(map(int, input().split()))
color = [input() for _ in range(n)]
vst = [[False for _ in range(m)]for _ in range(n)]

for i in range(n):
    for j in range(m):
        dfs(i,j,-1,-1)

print('NO')
