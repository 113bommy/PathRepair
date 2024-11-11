n = int(input())
a = []
for i in range(n):
	x, y = map(int, input().split())
	a.append((x, y))
d = {}
if n == 1:
	print(1)
	exit()
a = sorted(a)
for i in range(n):
	tc = a[i]
	for j in range(i + 1, n):
		nd = a[j]
		x1, y1, = tc[0], tc[1]
		x2, y2, = nd[0], nd[1]
		rz1 = x1 - x2
		rz2 = y1 - y2
		d[(rz1, rz2)] = d.get((rz1,rz2), 0) + 1
print(n - max(d.values()))
