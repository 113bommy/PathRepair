# python 3

n_val = int(input())
board = list()
for idx in range(n_val):
    board.append(input())
# print(board)

for row in range(n_val):
    for col in range(n_val):
        count = 0
        if row > 0:
            count += (board[row-1][col] == 'o')
        if row < n_val-1:
            count += (board[row+1][col] == 'o')
        if col > 0:
            count += (board[row][col-1] == 'o')
        if col < n_val-1:
            count += (board[row][col+1] == 'o')
        if count % 2 == 1:
            print('No')
            exit(0)
print('YES')
