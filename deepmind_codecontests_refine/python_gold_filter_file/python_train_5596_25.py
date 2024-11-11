s = input().split('.')
if s[0][-1]=='9':
	print('GOTO Vasilisa.')
else:
	if int(s[1][0])<5:
		print(s[0])
	else:
		print(int(s[0])+1)