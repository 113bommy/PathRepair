board = []
for i in range(8):
	board.append([i for i in input()])

blacks = []
whites = []

for i, li in enumerate(board):
	for j, lj in enumerate(board[i]):
		if board[i][j] == 'B':
			blacks.append([i,j])
		elif board[i][j] == 'W':
			whites.append([i,j])
min_white = 9
for i in whites:
	if i[0] < min_white:
		can = True
		for j in blacks:
			if i[1] == j[1] and i[0] < j[0]:
				can = False
		if can:
			min_white = i[0]

max_black = 0
for i in blacks:
	if i[0] > max_black:
		can = True
		for j in whites:
			if i[1] == j[1] and i[0] < j[0]:
				can = False
		if can:
			max_black = i[0]

if min_white <= 7 - max_black:
	print('A')
else:
	print('B')
