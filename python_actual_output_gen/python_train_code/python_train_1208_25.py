n, m = [int(i) for i in input().split()]
d = dict()
for i in range(n):
	a, b = [i.rstrip() for i in input().split()]
	d[b] = a
print(d)
for i in range(m):
	a, b = [i.rstrip() for i in input().split()]
	b = b[:-1]
	print(a, " ", b, "; #", d[b], sep="")