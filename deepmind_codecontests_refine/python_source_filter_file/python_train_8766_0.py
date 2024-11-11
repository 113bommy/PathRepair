import sys

def minp():
	return sys.stdin.readline().strip()

def mint():
	return int(minp())

def mints():
	return map(int, minp().split())


def solve():
	x0, y0, ax, ay, bx, by = mints()
	xs, ys, t = mints()
	c = 0
	p = [(x0,y0)]
	while True:
		x0, y0 = x0 * ax + bx, y0 * ay + by
		if abs(x0)+abs(y0) > 1e16*4:
			c += 1
			if c == 3:
				break
		else:
			p.append((x0,y0))
	n = len(p)
	r = 0
	for i in range(n):
		x1, y1 = p[i]
		d = abs(x1-xs)+abs(y1-ys)
		if d <= t:
			r = max(r, 1)
			for j in range(i+1,n):
				x2, y2 = p[j]
				if abs(x2-x1)+abs(y2-y1) <= t:
					r = max(r, j-i+1)
			for j in range(i):
				x2, y2 = p[j]
				if abs(x2-x1)+abs(y2-y1) <= t:
					r = max(r, i-j+1)
	print(r)

solve()

#01
# 123