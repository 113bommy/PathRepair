a = input()
b = []
h = ''
c = 0
for i in a:
	if i == 'Q':
		c += 1
if c == 0:
	print('Yes')
	exit(0)
r = -1
for i in range(1001):
	if i*i == c:
		r = i
		break
if r == -1:
	print('No')
	exit(0)
h = [a.split('Q')[0], a.split('Q')[-1]]
c = [len(h[0]), len(h[1])]
if c[0] % 2 != 0 or c[1] % 2 != 0:
	print('No')
	exit(0)
c[0] //= 2
c[1] //= 2
resp = ''
i = c[0]
while True:
	if i >= len(a):
		break
	if r == 0 and a[i] == 'Q':
		break
	resp += a[i]
	if r == 0 and a[i] == 'H':
		c[1] -= 1
	if c[1] == 0 and r == 0:
		break
	if a[i] == 'Q':
		r -= 1
	if r == -1:
		print('No')
		exit(0)
	i += 1


def hq(a):
	resp = ''
	for i in a:
		if i == 'H':
			resp += 'H'
		else:
			resp += a
	return resp

if a == hq(resp):
	print('Yes')
else:
	print('No')
