a = int(input())
b = list()
c = 'NO'
d = 0
for i in range(a):
	b.append(str(input()))
	if 'OO' in b[i] and d == 0:
		c = 'YES'
		b[i] = b[i].replace('OO','++')
		d = 1
print(c)
if c == 'YES':
	for i in b:
		print(i) 