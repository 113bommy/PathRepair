n, m = [int(x) for x in input().split()]

a = [[] * (m+1) for i in range(n+1)]
cols = [[0] * (m+1) for i in range(n+1)]
rows = [[0] * (m+1) for i in range(n+1)]

a[0] = '*' * (m+1)
for i in range(1, n+1):
    a[i] = '*'+input()
    
for i in range(1, n+1):
    for j in range(1, m+1):
        if a[i][j] == a[i][j-1]: 
            rows[i][j] = rows[i][j-1] + 1
            
for i in range(1, n+1):
    for j in range(1, m+1):
        if a[i][j] == a[i-1][j]: 
            cols[i][j] = cols[i-1][j] + 1
            
ans = 0
           
for i in range(1, n+1):
    for j in range(1, m+1):
        x = cols[i][j] + 1
        if i < x*3: 
            continue
        y = cols[i-x][j] + 1
        if x != y:
            continue
        z = cols[i-x-y][j] + 1
        if z < y:
            continue
        minx = 2 * m
        for l in range(0, x*3):
            minx = min(minx, rows[i-l][j])
        #print(i, j, x, y, minx)
        ans += (minx+1)
    
print(ans)