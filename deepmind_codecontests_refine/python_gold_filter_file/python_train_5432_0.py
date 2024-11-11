from sys import stdout
from itertools import product


def solve():
    global n, grid, query
    n = int(input())
    grid = [['*'] * n for _ in range(n)]
    grid[0][0] = '1'
    grid[n - 1][n - 1] = '0'

    def print_grid():
        for i in range(n):
            print(''.join(grid[i]))

    def query(i, j, k, l):
        print("? %d %d %d %d" % (i + 1, j + 1, k + 1, l + 1))
        stdout.flush()
        return int(input()) == 1

    def derive_value(i, j, k, l):
        if grid[k][l] != '*':
            return
        if i < k or j < l:
            q = query(i, j, k, l)
        else:
            q = query(k, l, i, j)
        if q:
            grid[k][l] = grid[i][j]
        else:
            grid[k][l] = '1' if grid[i][j] == '0' else '0'

    for i in range(0, n - 2, 2):
        derive_value(i, 0, i + 2, 0)
    for i, j in product(range(0, n, 2), range(0, n - 2, 2)):
        derive_value(i, j, i, j + 2)
    for i, j in product(range(0, n - 2, 2), range(0, n - 2, 2)):
        derive_value(i, j, i + 1, j + 1)
    for i in range(0, n - 2, 2):
        if grid[i + 2][i + 2] == '0':
            if query(i, i, i + 1, i + 2):
                grid[i + 1][i + 2] = '1'
                l = i + 1
                m = i + 2
            elif grid[i][i+2] != grid[i + 1][i + 1]:
                grid[i + 1][i + 2] = '0'
                l = i + 1
                m = i + 2
            else:
                if query(i, i + 1, i + 2, i + 2):
                    grid[i][i + 1] = '0'
                    l = i
                    m = i + 1
                elif grid[i + 1][i + 1] == '1':
                    grid[i + 1][i + 2] = '0'
                    l = i + 1
                    m = i + 2
                else:
                    grid[i][i + 1] = '1'
                    l = i
                    m = i + 1
            break
    for j in range(m - 2, -1, -2):
        derive_value(l, j + 2, l, j)
    for j in range(m, n - 2, 2):
        derive_value(l, j, l, j + 2)
    for i in range(l - 2, -1, -2):
        derive_value(i + 2, m % 2, i, m % 2)
    for i in range(l, n - 2, 2):
        derive_value(i, m % 2, i + 2, m % 2)
    derive_value(l % 2, m % 2, l % 2 + 1, m % 2 + 1)
    if l % 2 == 1:
        derive_value(l % 2 + 1, m % 2 + 1, l % 2 - 1, m % 2 + 1)
    else:
        derive_value(l % 2 + 1, m % 2 + 1, l % 2 + 1, m % 2 - 1)
    for j in range(1, n - 3, 2):
        derive_value(0, j, 0, j + 2)
    for j in range(0, n - 2, 2):
        derive_value(1, j, 1, j + 2)
    for i, j in product(range(0, n - 2), range(0, n)):
        derive_value(i, j, i + 2, j)
    print('!')
    print_grid()


if __name__ == '__main__':
    solve()











