def cumsum(a):
	b = []
	b.append(a[0])
	for i in range(1, len(a)):
		b.append(a[i]+b[i-1])
	return b

n, m = map(int, input().split(' '))
a = list(map(int, input().split(' ')))

b = cumsum(a)
c = []

for indx, i in enumerate(b):
	if i <= m:
		c.append(0)
	else:
		d = cumsum(sorted(a[:indx]))
		c.append(indx-len([t for t in d if t<=(m-a[indx])]))
for i in c:
	print(i, end=' ')
print()