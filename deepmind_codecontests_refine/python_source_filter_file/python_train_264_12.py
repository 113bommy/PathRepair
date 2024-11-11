ttt = list()
for i in range(4):
	row = input()
	if '.xx' in row or 'xx.' in row or 'x.x' in row:
		print('YES')
		quit()
	ttt.append(row)

for i in range(4):
	col = ''
	for j in range(4):
		col += ttt[j][i]
	if '.xx' in col or 'xx.' in col or 'x.x' in col:
		print('YES')
		quit()

for i in range(6):
	if i == 0:
		diag = ttt[1][0] + ttt[2][1] + ttt[3][2]
	elif i == 1:
		diag = ttt[1][0] + ttt[2][1] + ttt[3][2]
	elif i == 2:
		diag = ttt[0][2] + ttt[1][1] + ttt[2][0]
	elif i == 3:
		diag = ttt[1][3] + ttt[2][2] + ttt[3][1]
	elif i == 4:
		diag = ttt[0][0] + ttt[1][1] + ttt[2][2] + ttt[3][3]
	else:
		diag = ttt[0][3] + ttt[1][2] + ttt[2][1] + ttt[3][0]
	if 'xx.' in diag or '.xx' in diag or 'x.x' in diag:
		print('YES')
		quit()

print('NO')


