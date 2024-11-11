def solve(n, grid):
    x = [0 for i in range(3)]
    o = [0 for i in range(3)]
    
    for i in range(n):
        for j in range(n):
            if grid[i][j] == "O":
                o[(i+j)%3] += 1
            elif grid[i][j] == "X":
                x[(i+j)%3] += 1
    k = (sum(x)+sum(o)) // 3
    if k == 0:
        for i in range(n):
            print(grid)
        return
    
    for i in range(3):
        for j in range(3):
            if i != j and x[i]+o[j] <= k:
                cx, co = i, j
    
    for i in range(n):
        s = ""
        for j in range(n):
            if (i+j)%3 == cx and grid[i][j] == "X":
                s += "O"
            elif (i+j)%3 == co and grid[i][j] == "O":
                s += "X"
            else:
                s += grid[i][j]
        print(s)
        

t = int(input())
for i in range(t):
    n = int(input())
    grid = []
    for j in range(n):
        grid.append(input())
    solve(n, grid)