from collections import deque
import sys
sys.setrecursionlimit(20000)
#input = sys.stdin.readline
h,w = map(int,input().split())
a = [[j for j in input()] for i in range(h)]
used = [[0]*w for i in range(h)]
def dfs(x,y):
    if used[x][y]:
        return 0
    global go
    used[x][y] = 1
    if x-1 >=0 and a[x-1][y] != a[x][y]:
            go.add((x-1,y))
            dfs(x-1,y)
    if y-1 >=0 and a[x][y-1] != a[x][y]:
            go.add((x,y-1))
            dfs(x,y-1)
    if x+1 <h and a[x+1][y] != a[x][y]:
            go.add((x+1,y))      
            dfs(x+1,y)
    if y+1 <w and a[x][y+1] != a[x][y]:
            go.add((x,y+1))
            dfs(x,y+1)
ans = 0
for i in range(h):
    for j in range(w):
        go = set()
        if used[i][j]:
            continue
        dfs(i,j)
        kuro = 0
        siro = 0
        for k,l in go:
            if a[k][l] == "#":
                kuro += 1
            else:
                siro += 1
        ans += kuro*siro

print(ans)