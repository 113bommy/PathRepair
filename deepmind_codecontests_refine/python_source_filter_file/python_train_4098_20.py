import re
s = input()
if '@' not in s:
	print('NO')
	exit()
u, h = s.split('@', 1)
r = None
if '/' in h:
	if '/' in h[h.index('/') + 1: ]:
		print('NO')
		exit()
	h, r = h.split('/')
if not re.match('^\w{1,16}$', u):
	print('NO')
elif r is not None and not re.match('^\w{1,16}$', r):
	print('NO')
elif 1 > len(h) or len(h) > 32:
	print('NO')
else:
	h = h.split('.')
	if any(not re.match('^\w{,16}$', x) for x in h):
		print('NO')
	else:
		print('YES')
