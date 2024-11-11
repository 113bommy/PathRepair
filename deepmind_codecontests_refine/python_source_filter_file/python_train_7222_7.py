matriz = [list(map(str, input())) for i in range(4)]

flag = False
for i in range(4):
	for j in range(4):
		try:
			m = matriz
			sqr = [m[i][j], m[i][j+1], m[i+1][j], m[i+1][j+1]]
			if sqr.count('#') == 3 or sqr.count('.') == 4:
				flag = True
		except:
			continue

if flag:
	print('YES')
else:
	print('NO')
