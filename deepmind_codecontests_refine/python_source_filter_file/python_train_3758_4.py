import sys
from math import *

def minp():
	return sys.stdin.readline().strip()

def mint():
	return int(minp())

def mints():
	return map(int, minp().split())

n, m = mints()
A = [0]*n
h = [0]*m
for i in range(n):
	a, b = mints()
	A[i] = (b, a-1)
	h[a-1] += 1
A.sort()
r = 1e100
for k in range(1, n+1):
	b = h[::]
	w = [True]*n
	c = 0
	for i in range(n):
		p, id = A[i]
		if id != 0 and b[id] >= k:
			b[0] += 1
			b[id] -= 1
			c += p
			w[i] = False
	for i in range(n):
		p, id = A[i]
		if id != 0 and b[0] < k:
			b[0] += 1
			b[id] -= 1
			c += p
			w[i] = False
	#print(b,c)
	r = min(r, c)
print(r)