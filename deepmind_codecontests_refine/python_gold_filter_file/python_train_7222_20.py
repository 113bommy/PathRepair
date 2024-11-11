grid = list()
for i in range(0,4):
    row = list(input())
    grid.append(row)
flag = False
for i in range(0,3):
    for j in range(0,3):
        check = {'.' : 0, '#' : 0}
        check[grid[i][j]] += 1
        check[grid[i+1][j]] += 1
        check[grid[i][j+1]] += 1
        check[grid[i+1][j+1]] += 1
        if check['.'] >= 3 or check['#'] >= 3:
            flag = True
            break
    if flag:
        break
if flag:
    print('YES')
else:
    print('NO')