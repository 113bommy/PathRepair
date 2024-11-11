import sys

def minp():
	return sys.stdin.readline().strip()

def mint():
	return int(minp())

def mints():
	return map(int, minp().split())

def solve():
	n, a, b, da, db = mints()
	e = [[] for i in range(n+1)]
	for i in range(n-1):
		u, v = mints()
		e[u].append(v)
		e[v].append(u)
	if db < da*2+1:
		return False
	q = [0]*(n+2)
	ql = 0
	qr = 1
	d = [None]*(n+1)
	d[a] = 0
	q[0] = a
	while ql < qr:
		x = q[ql]
		ql += 1
		for v in e[x]:
			if d[v] is None:
				d[v] = d[x] + 1
				q[qr] = v
				qr += 1
	#print(d)
	if d[b] <= da:
		return False
	far = q[qr-1]
	#print(far, a, b, d[far])
	if d[far] >= da*2+1:
		return True
	ql = 0
	qr = 1
	d = [None]*(n+1)
	d[far] = 0
	q[0] = far
	while ql < qr:
		x = q[ql]
		ql += 1
		for v in e[x]:
			if d[v] is None:
				d[v] = d[x] + 1
				q[qr] = v
				qr += 1
	far2 = q[qr-1]
	#print(far, far2, d[far2])
	return d[far2] >= da*2+1


for i in range(mint()):
	print(["Alice","Bob"][solve()])

