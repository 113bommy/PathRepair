import sys

g = [input() for _ in range(4)]

for i in range(4):
    for j in range(4):
        if g[i][j] == 'x':
            if j < 2 and ((g[i][j + 1] == 'x' and g[i][j + 2] != 'o') or (g[i][j + 2] == 'x' and g[i][j + 1] != 'o')):
                print('YES')
                sys.exit(0)
            if j < 3 and j > 0 and (g[i][j + 1] == 'x' and g[i][j - 1] != 'o'):
                print('YES')
                sys.exit(0)
            if i < 2 and ((g[i + 1][j] == 'x' and g[i + 2][j] != 'o') or (g[i + 2][j] == 'x' and g[i + 1][j] != 'o')):
                print('YES')
                sys.exit(0)
            if i < 3 and i > 0 and (g[i + 1][j] == 'x' and g[i - 1][j] != 'o'):
                print('YES')
                sys.exit(0)
            if i < 2 and j < 2 and ((g[i + 1][j + 1] == 'x' and g[i + 2][j + 2] != 'o') or (g[i + 1][j + 1] != 'o' and g[i + 2][j + 2] == 'x')):
                print('YES')
                sys.exit(0)
            if i < 3 and i > 0 and j < 3 and j > 0 and (g[i + 1][j + 1] == 'x' and g[i - 1][j - 1] != 'o'):
                print('YES')
                sys.exit(0)
            if i < 2 and j > 2 and ((g[i + 1][j - 1] == 'x' and g[i + 2][j - 2] != 'o') or (g[i + 1][j - 1] != 'o' and g[i + 2][j - 2] == 'x')):
                print('YES')
                sys.exit(0)
            if i < 3 and i > 0 and j < 3 and j > 0 and (g[i + 1][j - 1] == 'x' and g[i - 1][j + 1] != 'o'):
                print('YES')
                sys.exit(0)
print('NO')
