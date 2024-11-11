import sys

def minp():
	return sys.stdin.readline().strip()

def mint():
	return int(minp())

def mints():
	return map(int, minp().split())

def solve():
	n, k, l = mints()
	x = 0
	pz = k
	for d in mints():
		z = l - d
		if z < 0:
			print("No")
			return
		if z > k:
			x = 0
		elif x < k:
			x = max(x + 1, k - z)
		elif x >= k:
			x = x + 1
			if x > 2*k:
				print("No")
				return
		pz = max(z, k)
	print("Yes")

for i in range(mint()):
	solve()
