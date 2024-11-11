n =input()
n = n.split('0')
l = []
for i in n:
	if i == '':
		l.append('0')
	else:
		l.append(str(len(i)))
print(''.join(l))