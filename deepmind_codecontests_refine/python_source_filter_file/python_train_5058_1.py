n = int(input())

la = [-1] * n
ra = [-1] * n
for i in range(n):
	la[i], ra[i] = map(int, input().split(' '))

m = int(input())
lb = [-1] * m
rb = [-1] * m

for i in range(m):
	lb[i], rb[i] = map(int, input().split(' '))

best = 0
pa = la[0]
qa = ra[0]
for i in range(1, n):
	if la[i] > pa:
		pa = la[i]
	if ra[i] < qa:
		qa = ra[i]
for j in range(m):
	pb = lb[j]
	qb = rb[j]
	if pb - qa > best:
		best = pb - qa
	if pa - qb > best:
		best = pa - pb
print(best)
