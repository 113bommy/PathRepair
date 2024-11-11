import sys

def minp():
	return sys.stdin.readline().strip()

def mint():
	return int(minp())

def mints():
	return map(int,minp().split())

c = [0]*9
n, sx, sy = mints()
for i in range(n):
	x, y = mints()
	x -= sx
	y -= sy
	k = 0
	if x < 0:
		k += 0
	elif x == 0:
		k += 1
	else:
		k += 2
	if y < 0:
		k += 0
	elif y == 0:
		k += 3
	else:
		k += 6
	c[k] += 1

r = (-1, sx, sy)
if sx - 1 >= 0 and sy - 1 >= 0:
	r = max(r, (c[0], sx - 1, sy - 1))
if sy - 1 >= 0:
	r = max(r, (c[0] + c[1] + c[2], sx, sy - 1))
if sx + 1 <= int(1e9) and sy - 1 >= 0:
	r = max(r, (c[2], sx + 1, sy - 1))
if sx + 1 <= int(1e9):
	r = max(r, (c[2] + c[5] + c[8], sx + 1, sy))
if sx + 1 <= int(1e9) and sy + 1 <= int(1e9):
	r = max(r, (c[8], sx + 1, sy + 1))
if sy + 1 <= int(1e9):
	r = max(r, (c[6] + c[7] + c[8], sx, sy + 1))
if sy + 1 <= int(1e9) and sx - 1 >= 0:
	r = max(r, (c[6], sx - 1, sy + 1))
if sx - 1 >= 0:
	r = max(r, (c[0] + c[3] + c[6], sx - 1, sy + 1))
#print(c)
print(r[0])
print(r[1], r[2])
