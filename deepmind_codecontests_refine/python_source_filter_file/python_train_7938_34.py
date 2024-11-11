


n,m,sx,sy = map(int,input().split())

grid = [[False]*m for i in range(n)]
sx-=1
sy-=1

print(sx+1,sy+1)
grid[sx][sy] = True
print(1,sy+1)
grid[0][sy] = True

for i in range(n):
    if(i==0):
        for j in range(sy-1,-1,-1):
            print(i+1,j+1)
            grid[i][j] = True

        for j in range(sy+1,m):
            print(i+1,j+1)
            grid[i][j] = True

    else:
        if(i%2==1):
            for j in range(m):
                if(grid[i][j] == False):
                    print(i+1,j+1)
                    grid[i][j] = True
        else:
            for j in range(m-1,-1,-1):
                if(grid[i][j] == False):
                    print(i+1,j+1)
                    grid[i][j] = True

