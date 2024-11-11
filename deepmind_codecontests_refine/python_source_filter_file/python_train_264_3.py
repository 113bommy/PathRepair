def checkwin(row,column,board):
    rxdisp = 0
    rxdot = 0
    for r in range(3):
        if row + r >= 4:
            break
        else:
            if board[row + r][column] == "x":
                rxdisp += 1
            elif board[row + r][column] == ".":
                rxdot += 1
    else:
        if (rxdisp >= 2 and rxdot >= 1) or rxdisp >= 3:
            return True
    cxdisp = 0
    cxdot = 0
    for c in range(3):
        if column + c >= 4:
            break
        else:
            if board[row][c + column] == "x":
                cxdisp += 1
            elif board[row][c+column] == ".":
                cxdot += 1
    else:
        if (cxdisp >= 2 and cxdot >= 1) or rxdisp >= 3:
            return True
    crxdisp = 0
    crxdot = 0
    for rc in range(3):
        if column + rc >= 4 or row + rc >= 4:
            break
        else:
            if board[row + rc][column + rc] == "x":
                crxdisp += 1
            elif board[row + rc][column + rc] == ".":
                crxdot += 1
    else:
        if (crxdisp >= 2 and crxdot >= 1) or rxdisp >= 3:
            return True
    crydisp = 0
    crydot = 0
    for rc in range(3):
        if column + rc < 0 or row + rc >= 4:
            break
        else:
            if board[row + rc][column - rc] == "x":
                crxdisp += 1
            elif board[row + rc][column - rc] == ".":
                crxdot += 1
    else:
        if (crydisp >= 2 and crydot >= 1) or rxdisp >= 3:
            return True

board = []
for n in range(4):
    board.append(input())
flag = 0
for row in range(4):
    if flag:
        break
    for column in range(4):
        if checkwin(row,column,board):
            #print(row,column)
            print("YES")
            flag = 1
            break
else:
    if flag != 1:
        print("NO")
