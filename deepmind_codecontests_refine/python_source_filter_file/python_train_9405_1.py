for i in range(int(input())):
	a = input()
	try:
		c = a.index('C')
		if c != len(a) + 1 and a.index('R') == 0:
			C, DC = [], int(a[c+1:])
			while DC:
				C.append(chr((DC % 26) + 64) if DC % 26 else 'Z')
				DC = int(DC / 26)
			print(''.join(C[::-1]), int(a[1:c]), sep='')
		else:
			raise()
	except:
		p, c = 0, 0
		for i in a:
			if 'A'<=i<='Z':
				p += 1
				c = (ord(i) - 64) + (c * 26)
			else:
				break
		print('R', a[p:], 'C', c, sep='')