n, m = map(int, input().split())
ab = []
for i in range(m):
	a,b = map(int, input().split())
	ab.append([a,b])
ab = sorted(ab, key=lambda x: x[1])
mn = ab[0][1]
c = 1
for i in ab:
	if i[0] > mn:
		c += 1
		mn = i[1]
print (c)