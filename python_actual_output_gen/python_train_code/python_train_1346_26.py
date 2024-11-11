x = "3 4".split(' ')
rows = int(x[0])
columns = int(x[1])
aux = 0
for i in range(rows):
	line = ''
	for j in range(columns):
		if i % 2 == 0:
			line += '#'
		else:
			if aux == 0:
				if j == columns-1:
					line += '#'
				else:
					line += '.'
			elif aux == 1:
				if j == 0:
					line += '#'
				else:
					line += '.'
	if line[columns-1] == '#' and line[0] == '.':
		aux = 1				
	elif line[columns-1] == '.' and line[0] == '#':
		aux = 0
	print(line)