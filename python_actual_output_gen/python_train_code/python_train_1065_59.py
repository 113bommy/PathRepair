WW = {'Q': 9, 'R': 5, 'B': 3, 'N': 3, 'P': 1}
WB = {'q': 9, 'r': 5, 'b': 3, 'n': 3, 'p': 1, '.': 0}
W = 0
B = 0
for i in range(8):
	s = input()
	for j in range(len(s)):
		if s[j] in WW:
			W += WW[s[j]]
		elif s[j] in WB:
			B += WB[s[j]]

if W > B:
	print('While')
elif W == B:
	print('Draw')
else:
	print('Black')