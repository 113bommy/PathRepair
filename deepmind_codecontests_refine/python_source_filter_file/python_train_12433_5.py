board = [[x for x in input().strip()] for y in range(3)]

xCount = sum([x.count('X') for x in board])
oCount = sum([x.count('0') for x in board])

if oCount > xCount or xCount > oCount+1:
    print('illegal')
elif xCount > oCount:
    legal = True
    if board[0][0] == '0' and board[1][1] == '0' and board[2][2] == '0':
        legal = False
    elif board[0][2] == '0' and board[1][1] == '0' and board[2][0] == '0':
        legal = False
    for x in range(3):
        if board[x] == ['0','0','0']:
            legal = False
        if board[0][x] == '0' and board[1][x] == '0' and board[2][x] == '0':
            legal = False
    if legal:
        win = False
        if board[0][0] == 'X' and board[1][1] == 'X' and board[2][2] == 'X':
            win = True
        elif board[2][0] == 'X' and board[1][1] == 'X' and board[2][0] == 'X':
            win = True
        for x in range(3):
            if board[x] == ['X','X','X']:
                win = True
            if board[0][x] == 'X' and board[1][x] == 'X' and board[2][x] == 'X':
                win = True
        if win:
            print('the first player won')
        else:
            if xCount + oCount == 9:
                print('draw')
            else:
                print('second')
    else:
        print('illegal')
else:
    legal = True
    if board[0][0] == 'X' and board[1][1] == 'X' and board[2][2] == 'X':
        legal = False
    elif board[0][2] == 'X' and board[1][1] == 'X' and board[2][0] == 'X':
        legal = False
    for x in range(3):
        if board[x] == ['X','X','X']:
            legal = False
        if board[0][x] == 'X' and board[1][x] == 'X' and board[2][x] == 'X':
            legal = False
    if legal:
        win = False
        if board[0][0] == '0' and board[1][1] == '0' and board[2][2] == '0':
            win = True
        elif board[2][0] == '0' and board[1][1] == '0' and board[2][0] == '0':
            win = True
        for x in range(3):
            if board[x] == ['0','0','0']:
                win = True
            if board[0][x] == '0' and board[1][x] == '0' and board[2][x] == '0':
                win = True
        if win:
            print('the second player won')
        else:
            print('first')
    else:
        print('illegal')
