n = int(input())
o = input()
c = input()

l = list(range(0, 10))  #[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
r = list(l)
r.reverse()	#[9, 8, 7, 6, 5, 4, 3, 2, 1, 0]

m = 0
for i in range(n):
	a, b = int(o[i]), int(c[i])
	p1 = abs(a - b)
	if a >=0 and a < 5: p2 = (a - l[0]) + (r.index(b) + 1)
	else: p2 = abs(a - r[0]) + (l.index(b) + 1)
	m += min(p1, p2)
	#print(m)
print(m)
