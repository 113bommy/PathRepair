grid = []
for _ in range(3):
    row = list(map(int,input().split(' ')))
    grid.append(row)
    

for i in range(3):
    for j in range(3):
        sum = grid[i][j]
        if j+1 < 3:
            sum += grid[i][j+1]
        if j-1 >= 0:
            sum += grid[i][j-1]
        if i+1 < 3:
            sum += grid[i+1][j]
        if i-1 >= 0:
            sum += grid[i-1][j]
            
        if sum % 2:
            print(0,end='')
        else:
            print(1,end='')
    
    #print('\n')