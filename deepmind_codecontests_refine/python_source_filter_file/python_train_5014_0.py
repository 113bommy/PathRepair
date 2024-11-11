l1 = []
l2 = []
s = input()
n = len(s)
if n == 2 or n == 3:
	print(s[0])
	exit(0)
p = 0
q = n - 1
i = 0
while (p + 1 <= q - 1):
	#i += 1
	a = s[p]
	b = s[p + 1]
	c = s[q]
	d = s[q - 1]
	if a == c:
		l1.append(a)
		l2.append(c)
		p += 1
		q -= 1
	elif a == d:
		l1.append(a)
		l2.append(d)
		p += 1
		q -= 2
	elif b == c:
		l1.append(b)
		l2.append(c)
		p += 2
		q -= 1
	elif b == d:
		l1.append(b)
		l2.append(d)
		p += 2
		q -= 2
	#print(a,b,c,d)
l2.reverse()
if p <= q:
	print(''.join(l1), end = '')
	print(s[p], end = '')
	print(''.join(l2))
else:
	print(''.join(l1), end = '')
	print(''.join(l2))

