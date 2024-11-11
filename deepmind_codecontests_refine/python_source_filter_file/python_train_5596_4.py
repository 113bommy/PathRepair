s=input()
x=s.index(".")
y=s[x+1:]
if s[x-1]!=9:
	if int(y)<5:
		print(s[:x])
	else:
		print(int(s[:x])+1)
else:
	print("GOTO Vasilisa.")