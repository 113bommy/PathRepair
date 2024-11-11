T = int(input())
for t in range(T):
    
    n = int(input())
    grid=[]
    ans=0
    for i in range(2):
        x = input()
        x = [int(i) for i in x]
        grid.append(x)
    # print(grid)
    for i in range(n):
        # print(i)
        if i>0 and grid[1][i]==1 and grid[0][i-1]==1:
            grid[0][i-1]=-1
        elif grid[1][i]==1 and grid[0][i]==0: grid[0][i]=-1
        elif i<n-1 and grid[1][i]==1 and grid[0][i+1]==1:
            grid[0][i+1]=-1
        
    print(grid)       
    print(grid[0].count(-1))
    
            
    