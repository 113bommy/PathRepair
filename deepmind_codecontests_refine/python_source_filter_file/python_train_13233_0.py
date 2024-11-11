n = int(input())
a = [int(x) for x in input().split()]
b = [0] * (max(a) + 1)
for i in range(n):
	b[a[i]] += 1
s = sum(a)
d = set(a)
c = []
for i in range(n):
	m = s - a[i]
	if m % 2 == 0 and m // 2 in d:
		if not(m // 2 == a[i] and b[m // 2] == 1):
			c.append(i)
if len(c) == 0:
	print(0)
else:
	print(len(c))
	for i in b:
		print(i + 1, end = ' ')
