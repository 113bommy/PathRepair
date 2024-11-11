def check(i, j):
    i1 = i
    j1 = j
    i2 = i
    j2 = j
    while j1 + 1 <= m - 1 and mat[i][j1 + 1] == 'X':
        j1 += 1
    while j2 - 1 >= 0 and mat[i][j2 - 1] == 'X':
        j2 -= 1
    if abs(j2 - j1) >= 4:
        return True
    i1 = i
    j1 = j
    i2 = i
    j2 = j
    while i1 + 1 <= n - 1 and mat[i1 + 1][j] == 'X':
        i1 += 1
    while i2 - 1 >= 0 and mat[i2 - 1][j] == 'X':
        i2 -= 1
    if abs(i1 - i2) >= 4:
        return True
    
    i1 = i
    j1 = j
    i2 = i
    j2 = j
    while i1 - 1 >= 0 and j1 + 1 <= m - 1 and mat[i1 - 1][j1 + 1] == 'X':
        i1 -= 1
        j1 += 1
    while i2 + 1 <= n - 1 and j2 - 1 >= 0 and mat[i2 + 1][j2 - 1] == 'X':
        i2 += 1
        j2 -= 1
    if abs(i1 - i2) >= 4 and abs(j1 - j2) >= 4:
        return True
    
    i1 = i
    j1 = j
    i2 = i
    j2 = j
    while i1 - 1 >= 0 and j1 - 1 >= 0 and mat[i1 - 1][j1 - 1] == 'X':
        i1 -= 1
        j1 -= 1
    while i2 + 1 <= n - 1 and j2 + 1 <= m - 1 and mat[i2 + 1][j2 + 1] == 'X':
        i2 += 1
        j2 += 1
    
    if abs(i1 - i2) >= 4 and abs(j1 - j2) >= 4:
        return True
    
    return False

n, m = 10, 10
mat = [list(input())for _ in range(m)]
for i in range(n):
    for j in range(m):
        if mat[i][j] == '.':
            mat[i][j] = 'X'
            if check(i, j):
                print("YES")
                exit(0)
            mat[i][j] = '.'      
print("NO")