import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline

def lii(): return list(map(int, input().split()))
def ii(): return int(input())


n, m = lii()
pairs = []

for i in range(m):
	pairs.append(lii())

rooks = {i:[(i, i)] for i in range(n)}

x, y = n, n

for each in pairs:
	p, q = each
	p-=1
	q-=1

	rooks[p].append([x, y])
	rooks[q].append([x+1, y])

	rooks[p].append([p, y])
	rooks[q].append([q, y])
	x += 2
	y += 1

for k, v in rooks.items():
	print(len(v))
	for rook in v:
		print(rook[0] + 1, rook[1] + 1)
