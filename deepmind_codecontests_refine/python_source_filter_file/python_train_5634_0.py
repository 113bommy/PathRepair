import sys
input=sys.stdin.readline
n,m=map(int,input().split())
grid=[]
ansgrid=[]
for i in range(n):
    grid.append(input())
    ansgrid.append([0]*m)
for i in range(n-2):
    for j in range(m-2):
        if grid[i][j]=='#' and grid[i+1][j]=='#' and grid[i+2][j]=='#' and grid[i][j+1]=='#' and grid[i][j+2]=='#' and grid[i+2][j+1]=='#' and grid[i+2][j+2]=='#' and grid[i+1][j+2]=='#':
            ansgrid[i][j]=1
            ansgrid[i+1][j]=1
            ansgrid[i+2][j]=1
            ansgrid[i+1][j+2]=1
            ansgrid[i+2][j+2]=1
            ansgrid[i+2][j+1]=1
            ansgrid[i][j+2]=1
            ansgrid[i][j+1]=1
flag=0
for i in range(n):
    for j in range(n):
        if grid[i][j]=='#' and ansgrid[i][j]==0 or grid[i][j]=='.' and ansgrid[i][j]==1:
            flag=1
if flag:
    print('NO')
else:
    print('YES')