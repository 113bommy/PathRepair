row = [True] * 8
col = [True] * 8
dpos = [True] * 15
dneg = [True] * 15


board = [['.', '.', '.', '.', '.', '.', '.', '.'] for i in range(8)]

import sys

file_input = sys.stdin

k = int(file_input.readline())

for line in file_input:
    r, c = map(int, line.split())
    row[r] = "INIT"
    col[c] = "INIT"
    dpos[r + c] = False
    dneg[r + (7 - c)] = False
    board[r][c] = 'Q'

def dfs(i = 0):
    if i == 8:
        for line in board:
            print(*line, sep='')
        return
    if row[i] == "INIT":
        dfs(i + 1)
    elif row[i]:
        for j in range(8):
            if col[j] == "INIT":
                pass
            elif col[j] and dpos[i + j] and dneg[i + (7 - j)]:
                row[i] = False
                col[j] = False
                dpos[i + j] = False
                dneg[i + (7 - j)] = False
                board[i][j] = 'Q'
                dfs(i + 1)
                row[i] = True
                col[j] = True
                dpos[i + j] = True
                dneg[i + (7 - j)] = True
                board[i][j] = '.'

dfs()