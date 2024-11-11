import math

def calc(x, y, r, d, nd):
	x = x + r * math.cos(math.radians(d))
	y = y + r * math.sin(math.radians(d))
	d -= nd
	return x, y, d

x = y = 0
d = 90

while True:
	r, nd = map(int, input().split(","))
	if r == nd == 0: break
	x, y, d = calc(x, y, r, d, nd)

print(int(x), "\n", int(y))