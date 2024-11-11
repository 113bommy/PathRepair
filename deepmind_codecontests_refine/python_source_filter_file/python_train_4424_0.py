inp=input()
fl=False
for i in range(len(inp)):
	for j in range(i,len(inp)):
		if inp[:i]+inp[j:]=='CODEFORCES':
			fl=True
if fl:
	print('Yes')
else:
	print('No')
