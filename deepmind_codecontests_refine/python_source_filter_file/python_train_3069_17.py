white = 0
black = 0
for i in range(8):
    board = input()
    white = white+9*board.count('Q')+5*board.count('R')+3*board.count('B')+3*board.count('K')+1*board.count('P')
    black = black + 9 * board.count('q') + 5 * board.count('r') + 3 * board.count('b') + 3 * board.count(
        'k') + 1 * board.count('p')
if white > black:
    print('White')
elif white < black:
    print('Black')
else:
    print('Draw')
