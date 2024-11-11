s = input()
vert = False
hor = False
for i in s:
	if i == '0':
		if vert: print(3, 1)
		else: print(1, 1)
		vert = not vert
	else:
		if hor: print(4, 1)
		else: print(4, 3)
		hor = not hor