import sys

def minp():
	return sys.stdin.readline().strip()

def mint():
	return int(minp())

def mints():
	return map(int, minp().split())

def pairss(n):
	res = []
	i = 1
	while i < n:
		for k in range(0,n,i*2):
			for j in range(i):
				res.append((j+k,j+i+k))
		i *= 2
	return res

def solve():
	n = mint()
	z = 1
	while z * 2 < n:
		z *= 2
	#print(z)
	q = pairss(z)
	res = []
	for a, b in q:
		res.append((a+1, b+1))
	for a, b in q:
		res.append((n-a, n-b))
	print(len(res))
	for a, b in res:
		print(a,b)

solve()
