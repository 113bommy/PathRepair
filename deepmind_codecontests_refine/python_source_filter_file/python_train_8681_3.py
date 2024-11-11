def check_row_wise(board):
	for row in board:
		if '.' not in row:
			return False
	return True

def check_col_wise(board):
	n = len(board)
	for i in range(n):
		flag = False
		for j in range(n):
			if board[j][i] == '.':
				flag = True
		if not flag:
			return False
	return True

if __name__ == '__main__':
	n = int(input())
	board = []
	
	for _ in range(n):
		x = list(input())
		board.append(x)

	row_check = check_row_wise(board)
	col_check = check_col_wise(board)
	print(col_check)
	if not row_check and not col_check:
		print(-1)
	elif row_check:
		for i, row in enumerate(board):
			x = row.index('.')
			print(i+1, x+1)
	else:
		for i in range(n):
			for j in range(n):
				if board[j][i] == '.':
					print(j+1, i+1)
					break