import sys

def check_win(board,player):
    # rows
    for i in range(0,3):
        if board[i][0] == board[i][1] == board[i][2] == player:
            return True
    # columns
    for i in range(0,3):
        if board[0][i] == board[1][i] == board[2][i] == player:
            return True
    # diagonals
    if board[0][0] == board[1][1] == board[2][2] == player:
        return True
    if board[2][0] == board[1][1] == board[0][2] == player:
        return True
    return False

board = []
for i in range(0,3):
    board.append(list(sys.stdin.readline()))

count_o = sum([row.count('O') for row in board])
count_x = sum([row.count('X') for row in board])

if count_x == count_o + 1:
    # Only the first player could have won if he made the last move
    if check_win(board,'O'):
        print("illegal")
    elif check_win(board,'X'):
        print("the first player won")
    elif count_x == 5:
        print("draw")
    else:
        print("second")
elif count_x == count_o:
    if check_win(board,'X'):
        print("illegal")
    elif check_win(board,'O'):
        print("the second player won")
    else:
        print("first")
else:
    print("illegal")
