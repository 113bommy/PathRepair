s=input()
v=s.split('.')
if v[0][-1]=='9':
	print('GOTO Vasilisa.')
else:
	if int(v[1][0])<5:
		print(v[0])
	else:
		s=v[0][:-1]+str(int(v[0][-1])+1)
		print(s)