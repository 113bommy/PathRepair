matrix = []
for i in range(10):
    matrix.append(list(input()))
alllines = matrix.copy()
for i in range(10):
    line = []
    for j in range(10):
        line.append(matrix[j][i])
    alllines.append(line)
for i in range(6):
    line = []
    x = i
    y = 0
    while x < 10 and y < 10:
        line.append(matrix[y][x])
        x += 1
        y += 1
    alllines.append(line)
for i in range(1, 6):
    line = []
    x = 0
    y = i
    while x < 10 and y < 10:
        line.append(matrix[y][x])
        x += 1
        y += 1
    alllines.append(line)
for i in range(9, 3, -1):
    line = []
    x = i
    y = 0
    while x >= 0 and y < 10:
        line.append(matrix[y][x])
        x -= 1
        y += 1
    alllines.append(line)
for i in range(1, 6):
    line = []
    x = 9
    y = i
    while x >= 0 and y < 10:
        line.append(matrix[y][x])
        x -= 1
        y += 1
    alllines.append(line)
f = False
for i in alllines:
    i = ''.join(i)
    for j in ['.XXXX', 'X,XXX', 'XX.XX', 'XXX.X', 'XXXX.']:
        if i.find(j) != -1:
            f = True
            break
if f:
    print('YES')
else:
    print('NO')