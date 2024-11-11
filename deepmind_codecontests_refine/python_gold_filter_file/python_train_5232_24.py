import sys

def minp():
	return sys.stdin.readline().strip()

def mint():
	return int(minp())

def mints():
	return map(int, minp().split())

def solve():
	n = mint()
	a = list(mints())
	b = list(enumerate(a))
	b.sort(key=lambda a:a[1])
	c1 = [0]*n
	#c2 = [0]*n
	c = 0
	h = 0
	p = -1
	for i, v in b:
		if i > p:
			c += 1
		else:
			c = 1
		h += 1
		c1[i] = h-c
		p = i
	c = 0
	h = 0
	p = -1
	ans = n+n
	for z in range(len(b)-1,-1,-1):
		i, v = b[z]
		if i < p:
			c += 1
		else:
			c = 1
		h += 1
		#c2[i] = h-c
		ans = min(ans, h - c + c1[i])
		p = i
	print(ans)

for i in range(mint()):
	solve()
