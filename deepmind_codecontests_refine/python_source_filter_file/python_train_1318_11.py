k = input()
a = k.count('-')
b = k.count('o')
if b != 0:
	if a == 0 or a%b == 0:
		print('Yes')
	else:
		print('No')
else:
	print('No')
