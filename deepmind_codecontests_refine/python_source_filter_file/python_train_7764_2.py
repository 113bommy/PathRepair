#!/usr/bin/env python3

# solution after hunt:(

[n, q] = map(int, input().strip().split())
bis = []
for i in range(q):
	u = int(input().strip())
	s = input().strip()
	bis.append((u, s))

d = len(bin(n)[2:])

def getk(u):
	b = bin(u)
	return len(b) - len(b.rstrip('0'))


def goLeft(u, k, d):
	if k == 0:
		return (u, k)
	else:
		return (u - 2**(k - 1), k - 1)

def goRight(u, k, d):
	if k == 0:
		return (u, k)
	else:
		return (u + 2**(k - 1), k - 1)

def goUp(u, k, d):
	if k == d - 1:
		return (u, k)
	elif getk(u - 2**k) == k + 1:
		return (u - 2**k, k + 1)
	else:
		return (u + 2**k, k + 1)

go = {'L': goLeft, 'R': goRight, 'U': goUp}

def process(u, s, d):
	k = getk(u)
	for c in s:
		(u, k) = go[c](u, k, d)
	return u

for u, s in bis:
	print (process(u, s, d))
