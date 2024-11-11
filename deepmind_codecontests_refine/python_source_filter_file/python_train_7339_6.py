
board = []
for i in range(8):
    board.append(input().strip())

# r, c system
R = 8
C = 8
N = 8

def yieldColumns(board):
    for i in range(8):
        A = []
        for j in range(8):
            A.append(board[j][i])
        yield A

def countDict(A):
    d = {}
    d['W'] = 0
    d['B'] = 0
    for l in A:
        if l not in d:
            d[l] = 0
        d[l] += 1
    return d

def whiteWinIn(c):
    isW = False
    count = 0
    for i in range(len(c)):
        j = 7-i
        if c[j] == 'W':
            isW = True
            count = 0
        if c[j] == 'B':
            isW = False

        if isW and i == 7:
            return count
        count += 1
    return -1

def blackWinIn(c):
    isW = False
    count = 0
    for i in range(len(c)):
        j = i
        if c[j] == 'B':
            isW = True
            count = 0
        if c[j] == 'W':
            isW = False

        if isW and i == 7:
            return count
        count += 1
    return -1

def solve(board):
    wWin = 1e10
    bWin = 1e10
    for c in yieldColumns(board):

        w = whiteWinIn(c)
        if w != -1:
            wWin = min(w, wWin)
        b = blackWinIn(c)
        if b != -1:
            bWin = min(b, bWin)

    if wWin < bWin:
        return 'A'
    else:
        return 'B'

print(solve(board))
