grid = [ ]
for i in range(8):
    grid.append(input())
w_result = b_result = 8
for j in range(8):
    pos_w = pos_b = 8
    for i in range(8):
        if grid[i][j] != '.':
            if grid[i][j] == 'W':
                pos_w = i
            break
    for i in range(7, -1, -1):
        if grid[i][j] != '.':
            if grid[i][j] == 'B':
                pos_b = i
            break
    if pos_w < 8:
        w_result = min(w_result, pos_w)
    if pos_b < 8:
        b_result = min(b_result, 7 - pos_b)
print('A' if w_result <= b_result else 'B')
