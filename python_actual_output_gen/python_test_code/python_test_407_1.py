n,m = map(int,input().split())
l = []
for i in range(n):
	t = input()
	l.append(t)
d = set({})
for i in range(m):
	z = 0
	t = []
	r = 0
	for j in range(n):
		if int(l[j][i]) > z:
			z = max(int(l[j][i]),z)
			r = t
	for j in range(n):
		if z == int(l[j][i]):
			t.append(l[j][i])
	for j in t:
		d.add(j)
print(len(d))
