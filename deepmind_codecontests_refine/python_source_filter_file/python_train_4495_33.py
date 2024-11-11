a = str(input())
b = ''
for i in a:
	if i in 'AEIOUaeiou':
		pass
	else:
		b = b + '.' + i.lower()
print(b)