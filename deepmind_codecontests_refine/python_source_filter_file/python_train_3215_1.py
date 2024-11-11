# AOJ 0110 Alphametic
# Python3 2018.6.21 bal4u

while 1:
	try:
		ab, s = list(input().split('='))
		a, b = list(ab.split('+'))
		start = 0
		if (len(a) > 0 and a[0] == '0') or (len(b) > 0 and b[0] == '0') \
			or (len(s) > 0 and s[0] == '0'): start = 1
		f = 1
		for x in range(start, 10):
			na = a.replace('X', str(x))
			nb = b.replace('X', str(x))
			ns = s.replace('X', str(x))
			if int(na) + int(nb) == int(ns):
				print(x)
				f = 0
				break
		if f: print("NA")
	except: break
