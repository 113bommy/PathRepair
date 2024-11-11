s=input()
n=len(s)
if s[0]=='h':
	print(s[0:4]+'://',end='')
	print(s[4],end='')
	for i in range(5,n-1):
		if s[i]=='r' and s[i+1]=='u':
			break
		else:
			print(s[i],end='')
	print('.'+'ru',end='')
	if i+2!=n :
		print('/'+s[i+2:n])
else:
	print(s[0:3]+'://',end='')
	print(s[3]+'://',end='')
	for i in range(4,n-1):
		if s[i]=='r' and s[i+1]=='u':
			break
		else:
			print(s[i],end='')
	print('.'+'ru',end='')
	if i+2!=n :
		print('/'+s[i+2:n])
