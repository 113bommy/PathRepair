line = input()
q = 0
n = len(line)
if n > 7:
	for i in range(0,n-7):
		if line[i] == line[i+1]:
			if line[i+1] == line[i+2]:
				if line[i+2] == line[i+3]:
					if line[i+3] == line[i+4]:
						if line[i+4] == line[i+5]:
							if line[i+5] == line[i+6]:
								q = q + 1
if q > 0:
	print('YES')
else:
	print('NO')