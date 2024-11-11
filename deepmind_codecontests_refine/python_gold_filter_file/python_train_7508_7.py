text = input()
flag = True
if(len(text) % 2 == 0):
	smb = text[0]
	for i in text:
		if i != smb:
			flag = False
			break
else:
	smb = text[0]
	for i in range(len(text)//2):
		if text[i] != smb:
			flag = False
			break
if flag:
	print('Impossible')
else:
	k = len(text)
	for i in range(1, k - 1):
		flag = True
		string = text[i:] + text[:i]
		for j in range((k + 1)//2):
			if string[j] != string[-j-1]:
				flag = False
				break
		if flag and string != text:
			break
		else:
			flag = False
	if flag:
		print(1)
	else:
		print(2)