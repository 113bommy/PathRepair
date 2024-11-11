conv_map = [[3, 3, 0, 4, 4, 0, 3, 3], [2, 2, 0, 3, 3, 0, 2, 2], [1, 1, 0, 2, 2, 0, 1, 1]]

res, prev = 0, None

a = [list(input()) for _ in range(6)]
for i in range(6):
    for j in range(8):
        if a[i][j] == '.':
            if conv_map[i // 2][j] > res:
                a[i][j] = 'P'
                if prev:
                    a[prev[0]][prev[1]] = '.'
                prev = (i, j)
                res = conv_map[i // 2][j]

print('\n'.join(''.join(ai) for ai in a))
