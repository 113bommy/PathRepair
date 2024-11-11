txt = input("")
j = 0
i = 0
if txt[0] == 'f':
	j = 3
	print(txt[:j], end='')
	print('://', end='')
elif txt[0] == 'h':
	j = 4
	print(txt[:j], end='')
	print('://', end='')	
i = txt.find('ru', j + 2)
print(txt[j:i], end='')
print('.', end='')
if len(txt[i+2:]) > 0:
	print(txt[i:i+2], end='')
	print('/', end='')
	print(txt[i+2:])
else:
	print(txt[i:i+2])