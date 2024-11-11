n = input()

i = n.index('.')
if n[i - 1] == '9':
	print("GOTO Vasilisa")
else:
	if int(n[i + 1]) >= 5:
		print(int(n[:i]) + 1)
	else:
		print(n[:i])