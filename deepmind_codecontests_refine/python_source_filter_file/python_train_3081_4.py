board = []
out = 0

for i in range(8):
    row = input()
    board.append(row)

print(board)
complete = True
for i in range(8):
    if board[i] != "BBBBBBBB":
        complete = False
        break

if complete:
    out = 8
    print(out)
else:
    for i in range(8):
        same = True
        for j in range(8):
            if board[i][j] != "B":
                same = False
                break
        if same:
            out += 1
    for i in range(8):
        same = True
        for j in range(8):
            if board[j][i] != "B":
                same = False
                break
        if same:
            out += 1
    print(out)
