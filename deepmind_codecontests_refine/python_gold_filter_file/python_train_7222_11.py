grid=[]
for i in range(4):
    grid.append(input())
for i in range(3):
    for j in range(3):
        square=[grid[i][j],grid[i][j+1],grid[i+1][j],grid[i+1][j+1]]
        if square.count('#')>2 or square.count('.')>2:
            print('YES')
            exit()
print('NO')
