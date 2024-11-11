import sys

def input():
	return sys.stdin.readline().strip()

def mint():
	return int(input())

def mints():
	return map(int, input().split())

for t in range(mint()):
	input()
	n, m = mints()
	a = [None]*m
	for i in range(m):
		r,c = mints()
		a[i] = (c,r-1)
	a.sort()
	b = []
	i = 0
	while i < m:
		c, r = a[i]
		i += 1
		x = (1<<r)
		if i < m and a[i][0] == c:
			x |= (1 << r)
			i += 1
		b.append((c, x))
	bad = False
	while len(b) > 0:
		c, p = b[-1]
		if p == 3:
			b.pop()
		elif len(b) < 2 or b[-2][1] != p^(((c-b[-2][0]+1)%2)*3):
			bad = True
			break
		else:
			b.pop()
			b.pop()
	if bad:
		print("NO")
	else:
		print("YES")
