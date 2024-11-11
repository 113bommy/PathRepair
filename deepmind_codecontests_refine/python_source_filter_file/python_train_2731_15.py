for q in range(int(input())):
	a = []
	for i in range(9):
		a.append(list(input()))
	if a[0][0] == '1':a[0][0] = '9'
	else:a[0][0] = '1'

	if a[1][4] == '1':a[1][4] = '9'
	else:a[1][4] = '1'

	if a[2][6] == '1':a[2][6] = '9'
	else:a[2][6] = '1'

	if a[3][1] == '1':a[3][1] = '9'
	else:a[3][1] = '1'

	if a[4][4] == '1':a[4][4] = '9'
	else:a[4][4] = '1'

	if a[5][7] == '1':a[5][7] = '9'
	else:a[5][7] = '1'

	if a[6][2] == '1':a[6][2] = '9'
	else:a[6][2] = '1'

	if a[7][5] == '1':a[7][5] = '9'
	else:a[7][5] = '1'

	if a[8][8] == '1':a[8][8] = '9'
	else:a[8][8] = '1'

	for i in range(9):
		print(''.join(a[i]))

	
